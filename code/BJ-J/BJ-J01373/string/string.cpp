#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
string s="";
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--) {
        int l;
        char c;
        cin>>l>>c;
        while(l--)
            s+=c;
    }
    for(int i=ceil(s.size()/2);i<s.size();i++)
        if(s[s.size()-i-1]!=s[i])
            cnt++;
    cout<<cnt;
    return 0;
}