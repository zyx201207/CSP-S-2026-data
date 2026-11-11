#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],cnt[maxn];
bool f[maxn];
string s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.in","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        s.erase(0);
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                s+=(a[j]+'0');
                f[a[j]]=1;
            }
            else{
                for(int i=0;i<s.size();i++){
                    if(s[i]==(a[j]+'0')){
                        s.erase(s.find(a[j]+'0'));
                        break;
                    }
                }
                s+=(a[j]+'0');
            }
        }
        for(char c:s){
            cnt[c-'0']++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
