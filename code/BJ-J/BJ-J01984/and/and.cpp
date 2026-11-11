#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
long long s[N],f2[50];
bool vis[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    f2[0]=1;
    for(int i=1;i<=30;i++){
        f2[i]=f2[i-1]*2;
    }
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
                //cout<<i<<" "<<j<<" "<<f2[i]<<" "<<s[j]<<" "<<(s[j]&f2[i])<<endl;
            if(vis[j]==0&&(s[j]&f2[i])!=0){
                cnt++;
            }
        }
        //cout<<i<<" "<<cnt<<endl;
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(vis[j]==0&&(s[j]&f2[i])==0){
                    vis[j]=1;
                }
            }
            ans+=f2[i];
        }
    }
    cout<<ans;
    return 0;
}
