#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
bool flag;
long long a[200005],p[35],ans,maxn;
void dfs(int x,int cnt,long long sum){
    if(x==n+1){
        if(cnt==m){
            ans=max(ans,sum);
        }
        return ;
    }
    if(cnt>m){
        return ;
    }
    dfs(x+1,cnt,sum);
    dfs(x+1,cnt+1,(sum&(a[x])));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(a[i]>3) flag=1;
    }
    if(m==1){
        cout<<maxn;
    }else if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++) ans=(ans&(a[i]));
        cout<<ans;
    }else if(m==2){
        maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,(a[i])&(a[j]));
            }
        }
        cout<<maxn;
    }else if(!flag){
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnt1++;
            if(a[i]==3) cnt3++;
            if(a[i]==2) cnt2++;
        }
        if(cnt3==0){
            if(cnt1<m) cout<<0;
            else cout<<1;
        }else{
            if(cnt1+cnt3<m){
                if(cnt1+cnt2+cnt3<m) cout<<0;
                else cout<<2;
            }else{
                cout<<3;
            }
        }
    }else if(n<=20){
        dfs(1,0,1111111);
        cout<<ans;
    }else{
        p[0]=1;
        for(int i=1;i<=30;i++){
            p[i]=p[i-1]*2;
        }
        bool flag1=0;
        for(int i=1;i<=n;i++){
            if(i!=p[i]-1){
                flag1=1;
            }
        }
        if(!flag1){
            cout<<maxn;
        }else{
            dfs(1,0,1111111111);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
