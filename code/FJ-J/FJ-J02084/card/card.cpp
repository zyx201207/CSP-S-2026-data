#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		string s="";
		for(int j=i;j<=n;j++)
		{
			if(s.find(a[j]+'0')!=-1) 
			{
				string s1="";
				for(int k=0;k<s.find(a[j]+'0');k++)
					s1+=s[k];
				s=s1;
			}
			s+=a[j]+'0';
		}	
		for(int j=0;j<s.size();j++)
			 b[s[j]-'0']++;
	}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}
