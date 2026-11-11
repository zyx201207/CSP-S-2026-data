#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n=0,x=0,ans=0;
char c;
string s="";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
    {

        cin>>x>>c;
        if(n==1)
        {
            cout<<0;
            return 0;
        }
        for(int j=0;j<x;j++)
        {
            s+=c;
        }
    }
    ll l=s.length();
    for(int i=0;i<l;i++)
    {
        if(s[l-1-i]!=s[i])
        {
            ans++;
        }
    }
    cout<<ans/2;
	return 0;
}

