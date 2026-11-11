#include<bits/stdc++.h>
using namespace std;
long long n,m,zmax;
long long a[500500];
long long bq(long long x){
	long long ml=m,maxl=1,i=1;
	while(ml>0){
		if(ml>=a[x]-a[x-i]&&x-i>=1){	
			ml=ml-(a[x]-a[x-i]);
			maxl++;
			i++;
			//cout<<x-i<<'\n';
		}
		else{
			break;
		}
	}
	return maxl;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
/*	for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';*/
	for(long long i=2;i<=n;i++){
		zmax=max(zmax,bq(i));
	}
	cout<<zmax;
	return 0;
}
