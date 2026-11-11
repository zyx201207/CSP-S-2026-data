#include<bits/stdc++.h>
using namespace std;
bool checkA(const vector<int> &a){
    auto check=[&](int x){
        x++;
        while(x!=0){
            if(x%2==1&&x!=1) return false;
            x/=2;
        }
        return true;
    };
    bool ok=true;
    for(int i=1;i<=a.size()-1;i++) ok&=check(a[i]);
    return ok;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20){
        int ans=0;
        auto dfs=[&](auto&& self,int id,int cnt,int sum){
            if(cnt==m){
                ans=max(ans,sum);
                return;
            }
            if(id==n+1) return;
            self(self,id+1,cnt+1,sum&a[id]);
            self(self,id+1,cnt,sum);
        };
        dfs(dfs,1,0,INT_MAX);
        cout<<ans<<'\n';
    }
    else if(n<=2000){
        if(m==1){
            cout<<*max_element(a.begin()+1,a.end())<<'\n';
        }
        else if(m==n){
            int ans=INT_MAX;
            for(int i=1;i<=n;i++) ans&=a[i];
            cout<<ans<<'\n';
        }
        else if(m==2){
            int ans=0;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    ans=max(ans,a[i]&a[j]);
            cout<<ans<<'\n';
        }
    }
    else{
        if(m==n-1){
            vector<int> pref(n+1),suff(n+2);
            pref[0]=suff[n+1]=INT_MAX;
            for(int i=1;i<=n;i++) pref[i]=pref[i-1]&a[i];
            for(int i=n;i>=1;i--) suff[i]=suff[i+1]&a[i];
            int ans=0;
            for(int i=1;i<=n;i++) ans=max(ans,pref[i-1]&suff[i+1]);
            cout<<ans<<'\n';
        }
        else if(checkA(a)){
            cout<<*max_element(a.begin()+1,a.end())<<'\n';
        }
    }
    return 0;
}