#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin)
	freopen("subway.out","w",stdout)
	int ans=0;
	int sum=0;
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<n;i++)
	{
		ans+=2;
	}
	
	int wm;
	cin>>wm;
	for(int r=1;r<q;r++)
	{
		sum+=2;
	}
	cout<<ans<<endl;
	cout<<sum;
	
	
	return 0;
 } 
