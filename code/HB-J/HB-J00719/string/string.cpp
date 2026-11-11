#include <bits/stdc++.h>
using namespace std;
string s;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m;
    string a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>a;
        while(m>0){
            s+=a;
            m--;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    cout<<'\n';
    return 0;
}
