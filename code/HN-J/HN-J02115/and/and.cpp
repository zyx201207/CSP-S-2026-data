#include<bits/stdc++.h>
using namespace std;
bool c(long long x,long long y){
	return y>x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+5]={};
	for(int z=1;z<=n;z++){
		cin>>a[z];
	}
	sort(a+1,a+1+n,c);
	int jg=a[n];
	for(int z=1;z<m;z++){
		jg=jg&a[n-z];
	}
	cout<<jg;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
