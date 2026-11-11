#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500005];
LL cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    string s;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    for(LL i=1;i<=n;i++){
        string s;
        for(LL j=i;j<=n;j++){
            char c=a[j]+'0';
            if(s.find(c)!=string::npos){
                int p=s.find(c),l=s.size();
                s.erase(p,l-p);
                s+=c;
            }else s+=c;
        }
        for(LL i=0;i<s.size();i++) cnt[s[i]-'0']++;
    }
    for(LL i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}

