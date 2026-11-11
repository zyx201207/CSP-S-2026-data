#include<bits/stdc++.h>
using namespace std;
char a[500010];
int cnt[500010],tot=0;
bool vis[500010]={0},viss[500010]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int T,m;
    cin>>T>>m;
    string s;
    int n=0;
    while(cin>>a[n]){
        n++;
    }
    int j=0;
    while(T--){
        for(int i=j;i<n;i++){
            s=s+a[i];
            if(vis[a[i]-'0']){
                int t=s.find(a[i]);
                for(int l=t;l<=s.size()-t+1;l++){
                    vis[a[i]-'0']=false;
                }
                s.erase(t);
                s=s+a[i];
                vis[a[i]-'0']=true;
            }else{
                vis[a[i]-'0']=true;
            }
        }
        j++;
        for(int i=0;i<s.size();i++){
            vis[s[i]-'0']=false;
            cnt[s[i]-'0']++;
        }
        s="";
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
