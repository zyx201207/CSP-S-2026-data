#include<bits/stdc++.h>
using namespace std;

int js(int x,int y)
{
	return int(x and y);
}

int n,m;
int ans[2*100005],a[2*100005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int mann=-1;
		for(int j=i+1;j<=n;j++)
		{
			int num=js(a[i],a[j]);
			mann=max(mann,num);
		}
		ans[i]=mann;
	}
	sort(ans+1,ans+n+1);
	cout<<ans[n];
	return 0;
}

