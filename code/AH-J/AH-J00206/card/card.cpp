#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long n,m,a[N],cnt[N];
void try1(){
    for(long long i=1;i<=n;i++){
        string s="";
        for(long long j=i;j<=n;j++){
            if(s.find(a[j]+'0')==std::string::npos) s+=(a[j]+'0');
            else{
                s.erase(s.find(a[j]+'0'),s.size()-s.find(a[j]+'0'));
                s+=(a[j]+'0');
            }
        }
        for(long long j=0;j<s.size();j++){
            long long x=s[j]-'0';
            cnt[x]++;
        }
    }
    for(long long i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
void try2(){
    for(long long i=1;i<=n;i++){
        vector<long long> g;
        g.clear();
        for(long long j=i;j<=n;j++){
            long long ok=0,pos;
            for(long long k=0;k<g.size();k++) if(g[k]==a[j]){ok=1;pos=k;}
            if(!ok) g.push_back(a[j]);
            else{
                for(long long k=g.size()-1;k>=pos;k--) g.pop_back();
                g.push_back(a[j]);
            }
        }
        for(long long j=0;j<g.size();j++){
            long long x=g[j];
            cnt[x]++;
        }
    }
    for(long long i=1;i<=m;i++) cout<<cnt[i]<<" ";
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];

    if(m<=79) try1();
    else try2();
    return 0;
}
