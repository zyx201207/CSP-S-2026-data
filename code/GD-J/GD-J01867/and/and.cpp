#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],d;
void f(long long t,long long l,long long s){
	if(t==m)return ;
	for(int i=l+1;i<=n;i++){
		if(t+1==m)d=max(d,s&a[i]);
		f(t+1,i,s&a[i]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n-m+1;i++){
		f(1,i,a[i]);
	}
	cout<<d;
	
	return 0;
}
