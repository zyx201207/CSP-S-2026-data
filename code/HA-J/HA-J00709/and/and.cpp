#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	int n=0;
	int m=0;
	long long ans=-10005;
	int a[1005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int d=a[i];
		int x=1;x<=n+2-i-m;x++;
		{
			for(int j=1;j<=m-1;j++){
			d=d and a[i+j+x];
		    }
		    if(d>ans){
			   ans=d;
		    }
		}
		
	}
	cout << ans;
	return 0;
}
