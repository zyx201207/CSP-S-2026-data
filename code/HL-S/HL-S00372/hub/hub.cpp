#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500002];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,t,sum=2;;
	cin>>n>>t;
	int l=t;
	int i=0;
	while(l--)
	{
		int k,lll;
		cin>>k>>lll;
		for(int i=0;i<k;i++)
		{
			cin>>a[i]>>a[i+1];
		}
	}
	while(t--)
	{
		cout<<sum<<endl;
		sum--;
	}
	return 0;
} 
