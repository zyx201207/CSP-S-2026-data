#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans,o;
ll a[500005],k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		k+=(i-1)*(a[i]-a[i-1]);
		if(k<=m)
		{
			int y=i+1;
			o=0;
			while(a[y]==a[i])o++,y++; 
			ans=max(ans,i+o);
		}
		if(k>m)
		{
			int j=1;
			int s=0; 
			int y=i+1;
			int dk=k;
			while(dk>m&&j<=i)
			{
				dk-=(a[i]-a[j]);
				j++;
			}
			if(dk>m)continue;
			while(a[y]==a[i])s++,y++; 
			ans=max(ans,i-j+s);
		}
	}
	cout<<ans;
	return 0;
} 
