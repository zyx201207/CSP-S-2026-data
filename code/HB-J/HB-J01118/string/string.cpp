#include<bits/stdc++.h>
using namespace std;
string s;
char ch;
int n,x;
long long ans,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>ch;
        ans+=x;
        while(x--)s=s+ch;
    }
    s=" "+s;
    for(long long i=1;i<=ans/2;i++){
        if(s[i]!=s[ans-i+1])cnt++;
    }
    cout<<cnt;
    return 0;
}