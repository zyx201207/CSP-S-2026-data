#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],sum;
int cmp(int x,int y){
	if(x!=y){
		return x>y;
	}
	else if(x==y){
		return x>y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	sum=a[1];
	for(int i=1;i<=m;++i){
		sum=a[i]&sum;
	}
	cout<<sum;
	return 0;
}
