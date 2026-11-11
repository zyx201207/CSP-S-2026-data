#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("cad.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int fg=0,n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		if(a[i]!=a[i+1])
		{
			fg=1;
			break;
		}
	}
	if(fg==0) cout<<1;
	else 
	{
		for(int i=0;i<m;i++) cout<<1<<" ";
		for(int i=0;i<n-m;i++) cout<<0<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
