#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],b,c;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	
	for(long long j=1;j<=n-m;j++){
		b=a[j-1];
		for(long long i=j;i<j+m-1;i++){
			b=b&a[i];
		}
		c=max(c,b);
	}
	cout<<c;
	return 0;
} 
