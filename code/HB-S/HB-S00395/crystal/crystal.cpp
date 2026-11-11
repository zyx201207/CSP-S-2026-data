#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,maxn=1;
long long a[500001],b[10001];
void dfs(int ci){
    for(int j=1;j<=200;j++){
        b[j]=0;
    }
    int man=0;
    if(ci<=m){
        for(int j=1;j<=n;j++){
            if(a[j]<0){
                b[a[j]+100]++;
            }
            else{
                b[a[j]]++;
            }
        }
        for(int j=1;j<=200;j++){
            if(b[j]>man){
                man=b[j];
            }
        }
        if(maxn<man){
            maxn=man;
        }
        if(ci==m){
            return;
        }
    }
    for(int j=1;j<=n-1;j++){
        a[j]++;
        dfs(ci+1);
        a[j]--;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    unsigned long long q=0,p=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            cnt=a[2]-a[1];
        }
        if(a[i]-a[i-1]!=cnt&&i!=1){
            q=1;
        }
        if(a[i]!=a[i-1]&&i!=1){
            p=1;
        }
    }
    sort(a+1,a+n+1);
    if(n<=16&&m<=1000){
        dfs(0);
    }
    if(p==0){
        cout<<n;
        return 0;
    }
    int kl=cnt,sum=1;cnt=0;
    if(q==0){
        while(cnt<=m){
            cnt+=kl*sum;
            maxn++;
            sum++;
        }
        maxn--;
    }
    cout<<maxn;
    return 0;
}
