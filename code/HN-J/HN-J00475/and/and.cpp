#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
long long n,m,a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long h=-1;
	for (int i=0;i<=n-m;i++){
		long long p=a[i];
		for (int j=i+1;j<i+m;j++){
			p&=a[j];
		}
		h=max(h,p);
	}
	cout<<h;
	return 0;
} 
