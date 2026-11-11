#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        char y;
        cin>>y;
        for(int i=1;i<=x;i++)
        {
            s+=y;
        }
    }
    int cnt=0;
    if(s.size()%2==0)
        for(int i=0;i<=(s.size()-1)/2;i++)
        {
            for(int j=s.size()-1;j>=i<=(s.size()-1)/2+1;i--)
            {
                if(s[i]!=s[j])cnt++;
            }
        }
    else
    {
        for(int i=0;i<=(s.size()-1)/2-1;i++)
        {
            for(int j=s.size()-1;j>=i<=(s.size()-1)/2+1;i--)
            {
                if(s[i]!=s[j])cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
