#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
int a[222222];
bool f[222222];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		f[i]=1;
		for(int j=i+1;j<=n;j++){
			int x=a[i]&a[j];
			ma=max(ma,x);
		}
		f[i]=0;
	}
	cout<<ma;
	return 0;
}
