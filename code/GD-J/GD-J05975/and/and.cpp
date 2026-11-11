#include<bits/stdc++.h>
using namespace std;
long long a[2005];
bool man(int o,int p){
	if(o>p) return 0;
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,z=0,x=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,man);
	for(int i=0;i<=n;i++){
		z=a[i];
		for(int j=1;j<m;j++){
			z=z&a[i+j];
		}
		x=max(x,z);
	}
	cout<<x;
	return 0;	
}
