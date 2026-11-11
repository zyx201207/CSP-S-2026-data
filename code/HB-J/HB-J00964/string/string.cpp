#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,ans=0;
    string s="";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        while(x--)
        {
            s=s+char(y);
        }
    }
    if(s.size()%2==1)
    {
        for(int i=s.size()/2,j=s.size()/2;i<s.size();i++,j--)
        {
            if(s[i]!=s[j])
                ans++;
        }
    }
    else
    {
        for(int i=s.size()/2,j=s.size()/2-1;i<s.size();i++,j--)
        {
            if(s[i]!=s[j])
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
