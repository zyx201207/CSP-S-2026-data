#include<bits/stdc++.h>
using namespace std;
int n,m,zd=0,z;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>zd)
			zd=a[i];
	}
	z=zd;
	zd=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]>zd){
				zd=a[j];
				a[j]=0;
			}
		}
		z=(z&zd);
		zd=0;
	}
	cout<<z;
	return 0;
}
