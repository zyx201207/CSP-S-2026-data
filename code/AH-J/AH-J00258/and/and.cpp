#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
int num[200005][35],vis[200005];
string s;
void f(int x,int i){
    int cnt=0;
    while(x){
        num[i][++cnt]=(x&1);
        x>>=1;
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    memset(vis,1,sizeof(vis));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f(a[i],i);
    }
    for(int i=31;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(num[j][i]==1&&vis[j]){
                cnt++;
            }
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(num[j][i]==0&&vis[j]){
                    vis[j]=0;
                }
            }
            s+="1";
        }else{
            s+='0';
        }
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        int l=(long long)(pow(2,i-1));
        ans+=l*(s[i]-'0');
    }
    cout<<ans;
    return 0;
}
