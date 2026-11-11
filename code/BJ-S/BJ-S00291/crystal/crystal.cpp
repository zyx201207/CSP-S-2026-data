#include<bits/stdc++.h>
using namespace std;
long n,m,a[500001],d[250000001],ans=0;
int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			d[i*(i-1)/2+j]=((a[i]-a[j]<0)?(a[j]-a[i]):(a[i]-a[j]));
		}
	}
	sort(d,d+(n-1)*(n-1)/2+1);
	int p=0;
	for(int i=0;i<n*n;i++){
		if(p>=m) break;
		//cout<<d[i]<<' ';
		ans++,p+=d[i];
	}
	cout<<ans;
	return 0;
}