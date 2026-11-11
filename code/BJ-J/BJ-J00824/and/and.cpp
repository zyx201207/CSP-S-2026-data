#include<bits/stdc++.h>
using namespace std;
inline bool check(int x){
    int cnt=0;
    while(x){
        if(x&1)cnt++;
        x>>=1;
    }
    return cnt==1;
}
int n,m,a[200010],vis[2000010],maxn=-1,res=-1;
inline void dfs(int x,int y){
    if(x==m){
        res=max(res,y);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[a[i]])continue;
        vis[a[i]]=true;
        dfs(x+1,y&a[i]);
        vis[a[i]]=false;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    bool flagB=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i],maxn=max(maxn,a[i]);if(a[i]!=i-1)flagB=false;}
    sort(a+1,a+1+n);
    if(m==1){
        cout<<maxn;
        return 0;
    }else if(m==n-1){
        int ans=a[n];
        for(int i=n-1;i>=2;i--)ans&=a[i];
        cout<<ans;
        return 0;
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++)ans&=a[i];
        cout<<ans;
    }else if(m==2){
        int ans=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }else if(maxn<=4){
        int mp[10],ans;
        mp[0]=mp[1]=mp[2]=mp[3]=0;
        for(int i=1;i<=n;i++){
            mp[a[i]]++;
        }
        if(mp[3]){
            m-=mp[3];
            ans=mp[3];
        }
        if(m<=0){
            cout<<ans;
            return 0;
        }
        if(m>mp[2]&&m>mp[1]){
            cout<<"0";
            return 0;
        }
        if(m>=mp[2]){
            cout<<"2";
            return 0;
        }else{
            cout<<"1";
            return 0;
        }
    }else if(check(n)&&flagB){
        int ans=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }else{
        dfs(0,INT_MAX);
        cout<<res;
        return 0;
    }
    return 0;
}
