#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
long long b[2][2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,x,i,j,k;
	cin>>c>>t;
	for (k=0;k<t;k++){
		cin>>n>>d;
		x=0;
		for (i=0;i<n;i++)
			cin>>a[i];
		for (i=0;i<n;i++){
			for (j=i+1;j<n;j++){
				if (a[j]-a[i]>d){
					b[0][x]=i;
					b[1][x]=j;
					x+=1;
				}
			} 
		}
		for (i=0;i<x;i++){
			if(a[b[1][i]]-a[b[0][i]]<3)
				x-=1;
		} 
	}
	cout<<x-2;
	cout<<x-1;
	return 0;
}
