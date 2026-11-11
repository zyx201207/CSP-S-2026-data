#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200010],lg[200010]={-1},sum,flagavr=1,flag4=1,flag2k=1,b[4];
bool isok(int x){
    for(int i=0;i<=20;i++)if(x==(1<<i)-1)return 1;
    return 0;
}
void dfs(int dep,int now,int cnt){
    if(cnt==m)ans=max(ans,now);
    for(int i=dep+1;i<=n;i++)dfs(i,now&a[i],cnt+1),dfs(i,now,cnt);
}
int main(){
    freopen("and.in","r",stdin),freopen("and.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0),cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i],sum&=a[i],lg[i]=lg[i/2]+1,
        flag4&=(a[i]<4),flag2k&=isok(a[i]),flagavr&=(i==1||a[i]-a[i-1]==1);
        if(a[i]<4)b[a[i]]++;
    }
    sort(a+1,a+1+n,greater<int>());
    if(m==1)ans=a[1];
    else if(m==n)ans=sum;
    else if(m==2)for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=max(ans,a[i]&a[j]);
    else if(m==n-1){
        for(int i=1;i<=n;i++){
            sum=(1<<20)-1;
            for(int j=1;j<=n;j++)
                if(i!=j)sum&=a[j];
            ans=max(ans,sum);
        }
    }else if(flag4){
        if(b[3]>=m)ans=3;
        else if(b[3]+b[2]>=m)ans=2;
        else if(b[3]+b[1]>=m)ans=1;
        else ans=0;
    }else if(flag2k)ans=a[m];
    else if(m<=20)dfs(0,(1<<20)-1,0);
    else if(isok(a[1])&&a[1]==n-1&&a[n]==0&&flagavr)ans=n-(1<<lg[m]);
    cout<<ans;
    return 0;
}