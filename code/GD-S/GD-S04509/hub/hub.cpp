#include<bits/stdc++.h>
using namespace std;
int log(int n)
{
	int i=1;
	for(;i<n;i*=2)
	{
		i++;
		i--;
	}
	return i;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		vector<int>mp(n);
		vector<int>md(n);
		for(int i=0;i<n;i++) cin>>mp[i]>>md[i];
		cout<<log(n)<<endl;
	}
	return 0; 
}
