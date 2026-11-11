#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    while (n--){
        int a;
        char b;
        cin>>a>>b;
        s.insert(0,a,b);
    }
    long long i,x=s.size(),cnt=0;
    for (i=0;i<x/2+1;i++){
        if (s[i]!=s[x-i-1]){
            s[i]=s[x-i-1];
            cnt++;
        }
        string c=s;
        reverse(c.begin(),c.end());
        if (c==s){
            cout<<cnt;
            return 0;
        }
    }
    cout<<cnt;
    return 0;
}
