#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[500005];
int f[500005];
string s;
int n,m;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s+=' ';
            for(int k=0;k<s.size();k++){
                bool flag=0;
                if(s[k]==a[j]){
                    s.erase(k,s.size()-k-1);
                    flag=1;
                }
                if(flag)
                    break;
            }
            s+=a[j];
        }
        for(int j=0;j<s.size();j++)
            f[s[j]-'0']++;
        s="";
    }
    for(int i=1;i<=m;i++)
        cout<<f[i]<<' ';
    return 0;
}
