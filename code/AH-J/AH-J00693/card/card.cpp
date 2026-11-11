#include<bits/stdc++.h>
using namespace std;
long long cnt[300010];
char c[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    string s,l;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>c[i];
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            l="";
            for(long long k=0;k<s.size();k++){
                if(s[k]!=c[j])l+=s[k];
                else break;
            }
            s=l+c[j];
        }
        for(long long j=0;j<s.size();j++)cnt[s[j]-'0']++;
        s="";
    }
    for(long long i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
