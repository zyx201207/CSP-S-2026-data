#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,cnt=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>m;
        cin>>s;
        for(long long j=1;j<=m;j++) a+=s;
    }
    string b=a;
    reverse(a.begin(),a.end());
    for(long long i=0;i<a.size();i++){
        if(a[i]!=b[i])cnt++;
    }
    cout<<cnt/2;
    return 0;
}

