#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,ans = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        long long t;
        string ps;
        cin>>t>>ps;
        for(long long j = 1;j<=t;j++) s+=ps;
    }
    long long midd = s.length()/2,len = s.length();
    for(long long i = 0,j = len-1;i<midd,j>midd;i++,j--){
        if(s[i]!=s[j]) ans++;
    }
    cout<<ans;
    return 0;
}

