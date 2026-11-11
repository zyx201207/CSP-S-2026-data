#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    if(n==1)
    {

        cout<<0;
        return 0;
    }
    string s="";
    for(int i=1;i<=n;i++)
    {

        int x;
        cin>>x;
        string w;
        cin>>w;
        for(int i=1;i<=x;i++)
        {
            s+=w;
        }
    }
    string s1=s;
    reverse(s1.begin(),s1.end());
    if(s==s1)
    {

        cout<<0;
        return 0;
    }
    int len=s.size()-1;
    int h=floor(len/2);
    int cnt=0,cnt2=0;
    for(int i=0;i<h;i++)
    {
        if(s[i]!=s[len-i])
        {

            cnt++;
        }

    }
    for(int i=len;i>=h;i--)
    {
        if(s[i]!=s[len-i])
        {

            cnt2++;
        }

    }
    cout<<min(cnt,cnt2);
}
