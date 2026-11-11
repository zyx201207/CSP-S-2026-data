#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
long long n,m,a[N],r;
void v(int dp,int t,int u[]){
	if(dp>=m)return;
	for(int i=1;i<=n;i++){
		if(u!r){
			v(r,u)
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	v(1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){if(i==j)continue;
			r=max(r,a[i]&a[j]);
		}
	}
	cout<<r;
	return 0;	
}
