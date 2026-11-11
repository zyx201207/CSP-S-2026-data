#include<bits/stdc++.h>
using namespace std;
char w[1000000002];
long long sum;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int s;
		char d;
		cin>>s>>d;
		for(int j=0;j<s;j++)
		{
			w[sum]=d;
			sum++;
		}
	}
	int e=sum-1;
	for(int i=0;i<sum;i++)
	{
		if(w[i]==w[e-i])
		{
			break;
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
