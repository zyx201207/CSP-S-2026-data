#include<bits/stdc++.h>
using namespace std;
struct H{
    long long a;
    char c;
};
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);                                                              
    long long n,cnt=0;
    cin>>n;
    H p[n+5];
    for(long long i=0;i<n;i++){
        cin>>p[i].a>>p[i].c;
        for(long long j=0;j<p[i].a;j++){
            s+=p[i].c;
        }
    }
    long long x=s.size()-1;
    for(long long i=0;i<s.size()/2;i++){
          if(s[i]!=s[x-i])cnt++;
    }
    cout<<cnt;
    return 0;
}
