#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],s;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[1];
	return 0;
}
