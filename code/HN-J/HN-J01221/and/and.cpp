#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],k;
void f(long long st,long long m,long long sk){
	if(sk<=k||sk==0)return;
	if(st>n)return;
	if(m==0){
		k=sk;
		return;
	}
	for(long long i=st;i<n-m;i++){
		f(i+1,m-1,sk&(a[i]));
	}
}
bool st(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,st);
	f(0,m,0x7fffffff);
	cout<<k;
	return 0;
}
