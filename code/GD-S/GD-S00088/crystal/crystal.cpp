#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m;
bool check(int x){
	if(x==1)
		return 1;
	int res=0;
	for(int i=1;i<=x-1;i++)
		res+=a[x]-a[i];
	if(res<=m)
		return 1;
	for(int k=x+1;k<=n;k++)
	{
		int tmp=a[k]-a[k-1];
		res-=a[k-1]-a[k-x];
		res+=x*tmp;
		if(res<=m)
			return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=0,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	cout<<l<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
