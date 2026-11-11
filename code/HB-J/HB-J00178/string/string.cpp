#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
char c[200010];
int cnt;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    for(int i=0;i<(((int)s.size()-1)/2-1);i++){
        for(int j=(((int)s.size()-1)/2+1);j<s.size();j++){
            if(s[i]!=s[j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
