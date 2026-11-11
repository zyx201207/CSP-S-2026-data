#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
long long akcspj[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long maxx=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		string s="";
		long long ff=i;
		for(int j=i;j<=n;j++)
		{
			string s1=to_string(a[ff]);
			s+=s1;
			for(int l=0;l<s.size()-1;l++)
			{
				string s2="";
				s2+=s[l];
				if(s2==s1)
				{
					s.erase(l+1,ff-1);
				}
			}
			ff++;
		}
		for(int j=0;j<s.size();j++) akcspj[s[j]-'0']++;
	}
	for(int i=1;i<=maxx;i++) cout<<akcspj[i]<<' ';
	return 0;
}
