#include <bits/stdc++.h>
using namespace std;
int ans;
const int N=2e5+5;
int a[N],b[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int max=-1;
			if(a[i]==b[j])     continue;
			if(max<a[j])     max=a[j];
			b[i]=max;
		}	
	}
	for(int i=1;i<m;i++)
	{
		if(i==1)    ans=(b[i]|b[i+1]);
		else    ans=(ans|b[i+1]);
	}
	cout<<ans;
	return 0;
}                                                                                                                                                                             
