#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string s;
    char b;
    long long n,m,a=0;
    long long ans=0;
    cin >>n;
    for(long long i=0;i<n;i++){
        cin>>m>>b;
        for(long long j=a,a+=m;j<m;j++){
            s[j]=b;
        }
    }
for (long long i=0;i<a/2;i++){
    if(s[i]!=s[a+1-i]){
        ans++;
    }
}
cout <<ans;
return 0;
}