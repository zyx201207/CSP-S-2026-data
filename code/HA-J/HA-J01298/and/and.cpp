#include<bits/stdc++.h>
using namespace std;
long long n,m,i,a[200005],d;
bool c(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,c);
	d=a[0];
	for(i=0;i<m;i++){
		d&=a[i];
	}
	cout<<d;
	return 0;
}
