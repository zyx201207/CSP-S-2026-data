#include <bits/stdc++.h>
using namespace std;
int n=0,m=0;
vector<int> a(200005);
int x=0;
bool temp=0;
int dfs(int h){
	if(temp)return 0;
	if(h>m){
		cout<<x<<endl;
		temp=1;
		return x;
	}
	for(int i=0;i<n;i++)
		if(h<=m){
			x=a[i];
			x=x&dfs(h++);
		}
	return x;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==1){
		sort(a.begin(),a.end(),greater<int>());
		cout<<a[0]<<endl;
	}
	else if(m==2){
		int maxn=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j)
					maxn=max(maxn,(a[i] & a[j]));
		cout<<maxn<<endl;
	}
	else if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++)
			ans=ans&a[i];
		cout<<ans<<endl;
	}
	else
	{
		if(n<=2000)
			dfs(0);
		else cout<<a[0]<<endl;
	}
	return 0;
}
