#include<bits/stdc++.h>
using namespace std;
long long m;
int a[500005];
bool f(int x)
{
	int z=0;
	for(int i=1;i<=x;i++){
		z+=a[x]-a[i];
	}
	return z<=m;
}
bool cmp(int a,int b){
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=0;cin>>n>>m;
	if(m<=100000000){
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1,cmp);
		int l=1,r=n,mid=(l+r)/2;
		while(l<=r){
			mid=(l+r)/2;
			if(f(mid)){
				l=mid+1;
			}
			else 
			{
				r=mid-1;
			}
		}
		ans=r;
	}
	else{
		cin>>a[1]>>a[2];
		int k=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m>k*i*(i+1)/2){
				ans=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}