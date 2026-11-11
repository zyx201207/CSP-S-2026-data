#include<bits/stdc++.h>
using namespace std;
int a[200005],n,u[200005];
char c[200005];
long long sum=0;
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
	int l=1,r=n;
	u[l]=a[l],u[r]=a[r];
	while(l<r){
		if(c[l]!=c[r]){
			int m=min(u[l],u[r]);
			sum+=m;
			if(m==u[l])l+=1,u[l]=a[l];
			else u[l]-=m;
			if(m==u[r])r-=1,u[r]=a[r];
			else u[r]-=m;
		}
		else {
			int m=min(u[l],u[r]);
			if(m==u[l])l+=1,u[l]=a[l];
			else u[l]-=m;
			if(m==u[r])r-=1,u[r]=a[r];
			else u[r]-=m;
		}
	}
	cout<<sum<<endl;
	return 0;
}
