#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s="";
bool flag=true;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num;
        char c;
        cin>>num>>c;
        if(num>1)
        {
            flag=false;
        }
        for(int i=1;i<=num;i++)
        {
            s+=c;
        }
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(flag==true)
    {
        cout<<s.size()-1;
        return 0;
    }
    for(int i=0;i<(int)s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}