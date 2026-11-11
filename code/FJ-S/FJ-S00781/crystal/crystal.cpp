/*
8 10
-3 2 8 5 3 7 -1 2
4
8 12
-3 2 8 5 3 7 -1 2
5

*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],f[500010],c[500010],ma;//f:´ÎÊý 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	f[1]=0;
	long long l=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+(i-l)*c[i];
//		cout<<f[i]<<" ";
			while(f[i]>m){
				f[i]-=(a[i]-a[l]);
				l++;
			}
//		cout<<i-l+1<<endl;
		ma=max(ma,i-l+1);
	}
	cout<<ma;
	return 0;
} 
