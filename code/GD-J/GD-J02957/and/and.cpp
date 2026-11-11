#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,f[N];
vector<int> s[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=m;j>=1;j--)
		{
			if(j==1)
				f[j]=max(f[j],x);
			else
				f[j]=max(f[j],f[j-1]&x);
		}	
	}
	cout<<f[m];
}
