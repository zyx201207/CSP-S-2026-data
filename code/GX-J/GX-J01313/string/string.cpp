#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s;
    for (long long i=1;i<=n;i++){
        long long a;
        char b;
        cin>>a>>b;
        for (long long i=1;i<=a;i++) s+=b;
    }
    //cout<<s.size()<<'\n';
    //cout<<s.substr(2,3)<<'\n';
    //cout<<s.size()/2+1+(s.size()%2==0 ? 0:1)<<'\n';
    string l=s.substr(0,s.size()/2),r=s.substr(s.size()/2+(s.size()%2==0 ? 0:1),s.size());
    long long cnt=0;
    for (long long i=0;i<l.size();i++){
        if (l[i]!=r[i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
