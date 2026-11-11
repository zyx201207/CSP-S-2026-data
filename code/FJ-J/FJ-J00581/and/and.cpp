#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ma=-99;
	cin>>n>>m;
	long long a[200050]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++){
		long long q=a[i];
		for(long long j=1;j<m;j++){
			q=q&a[i+j];
		}
		ma=max(ma,q);
	}
	cout<<ma;
} 
