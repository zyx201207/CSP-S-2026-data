#include<bits/stdc++.h>
using namespace std;
int n,m,a[200500],ans=0;
void dg(int mem,int num,int lam){
	if(mem>m){
		ans=max(ans,num);
		return;
	}
	for(int i=lam;i<=n-m+mem;i++){
		if(mem==1)num=a[i];
		dg(mem+1,(num&a[i]),i+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1&&m==n)ans=a[i];
		if(m==1)ans=max(ans,a[i]);
		if(m==n&&i!=1)ans&=a[i];
	}
	if(m!=1)dg(1,0,1);
	cout<<ans;
	return 0;
}
