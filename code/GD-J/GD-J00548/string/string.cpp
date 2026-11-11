#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
string s;
vector<ull> a;
vector<string> c;
ull n,cnt=0;
ull g=1;
ull siz;
char header;
char back;
bool check(){
    for(ull i=0;i<s.size();++i){
        header=s[i];
        back=s[s.size()-1-i];
        if(header != back) return false;
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ull i=0;i<n;++i){
        ull ai;
        string ci;
        cin>>ai>>ci;
        a.push_back(ai);
        c.push_back(ci);
    }
    g = a[0];
    for(ull i=1;i<n;++i){
        g = gcd(g,a[i]);
    }
    for(ull i=0;g!=1&&i<n;++i){
        a[i] = a[i]/g;
    }
    if(n == 1) goto Zer;
    for(ull i=0;i<n;++i){
        for(ull j=0;j<a[i];++j){
            s=s+c[i];
        }
    }
    siz=s.size();
    if(check()) goto Zer;
    header=s[0];
    back=s[siz-1];
    for(ull i=(siz/2);i<siz;++i){
        header=s[i-(siz/2)];
        back=s[siz-1-(i-(siz/2))];
        if(header != back) return cnt++;
    }
    cout<<cnt;
    return 0;
    Zer:
    cout<<0;
    return 0;
}