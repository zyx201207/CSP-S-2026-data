#include<bits/stdc++.h>
using namespace std;
int n,len;
string s;
int f()
{
    int cnt=0;
    for(int i=0;i<len/2;i++) if(s[i]!=s[len-i-1]) cnt++;
    return cnt;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    if(n==1)
    {
        cout<<"0";
    }
    if(n==2)
    {
        int len1,len2;
        char a,b;
        cin>>len1>>a>>len2>>b;
        if(a==b) cout<<"0";
        else cout<<min(len1,len2);
    }
    else
    {
        while(n--)
        {
            int len1;
            cin>>len1;
            char a;
            cin>>a;
            for(int i=len;i<len+len1;i++) s+=a;
            len+=len1;
        }
        int ans=f();
        cout<<ans;
    }
    return 0;
}
