#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int ans;
string s="";
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=0;j<=a[i];j++)
        {
           s=s+c[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]!=s[s.size()+1-i])
        {
            ans++;
        }
    }
    return 0;
}