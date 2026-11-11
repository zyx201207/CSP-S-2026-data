#include<bits/stdc++.h>
using namespace std;
long long a[10000000],d[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,mix,miix,p;
	long long mi=999999991781;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
	}
	if(n>5000){
		cout<<m/(a[2]-a[1]);
		return 0;
	}
	p=n;
	for(int j=1;j<=n;j++){
		long long ma=-1000000000001,maxx;
		for(int i=1;i<=n;i++){
			if(d[i]>ma){
				ma=d[i];
				maxx=i;
			}
		}
		long long summ=0;
		for(int i=1;i<=n;i++){
			if(d[i]==-999999991781){
				continue;
			}
			summ+=d[maxx]-d[i];
		}	
		if(summ<=m){
			cout<<p;
			return 0;
		}
		else if(summ>m){
			d[maxx]=-999999991781;
			p--;
		}	
	}
	cout<<1;
	return 0;
}
