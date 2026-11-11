#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200000];
int p(int x){
	int r;
	int u;
	int d=1;
	while(x!=0){
		r=x%2;
		x/=2;
		u+=r*d;
		d=d*10;
		r=0;
	}
	return u;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n];
	return 0;
} 
