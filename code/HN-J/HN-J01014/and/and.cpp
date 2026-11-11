#include<bits/stdc++.h>
using namespace std;
bool cmp_(int a,int b){
	if(b<a) return true;
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[200005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp_);
	long long num=a[1];
	for(int i=1;i<=m;i++){
		num&=a[i];
	}
	cout<<num;
	return 0;
}
