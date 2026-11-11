#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x;
        char c;
        cin>>x>>c;
        while(x--) s+=c;
    }
    for(int i=0,j=s.size()-1;; i++,j--)
    {
        if(s[i]!=s[j]) cnt++;
        if(i==j || i-j==1) break;
    }
    cout<<cnt;
    return 0;
}
