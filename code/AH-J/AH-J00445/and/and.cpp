#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[200005],sum[200005],maxn;
void dfs(int t,int i,int c,int summ){
    if(c==1) summ=a[i];
    if(c>m) return;
    if(i==n){
        if(c==m){
            maxn=max(maxn,summ);
        }
        return;
    }
    dfs(0,i+1,c,summ);
    dfs(1,i+1,c+1,(summ&a[i+1]));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    sum[0]=a[1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]&a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
    }else if(m==n){
        cout<<sum[n];
    }else if(a[n]<4){
        int t[200005]={0};
        for(int i=1;i<=n;i++){
            t[a[i]]++;
        }
        if(m==1){
            if(t[3]>0) cout<<3;
            else if(t[2]>0) cout<<2;
            else if(t[1]>0) cout<<1;
        }else{
            if(t[3]>0) cout<<3;
            else if(t[2]>0&&t[1]>0) cout<<3;
            else if(t[2]>0) cout<<2;
            else if(t[1]>=0) cout<<1;
        }
    }else{
        dfs(0,0,0,0);
        cout<<maxn;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
