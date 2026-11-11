#include <bits/stdc++.h>
using namespace std;
//__int128 n,a,k,ans,tans;
long long n,a,k,ans=0,tans=0;
/*map<long long,long long> n;
map<long long,long long> a;
map<long long,long long> k;
map<long long,long long> ans;
map<long long,long long> tans;*/
char c;
string s,hws;
int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
	  	while(a!=0)
	  	{
	  	   k=i;
		   s+=c;
		   k++; 
		   a--;
	    }
	}
	hws=s;
	reverse(hws.begin(),hws.end());
	if(hws==s) 
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<s.size();i++)
	{
		   if(s[i]!=hws[i])
		   {
		   	   ans++;
		    }	
	}
	tans=ans/2;
	cout<<tans;
	return 0;
}
