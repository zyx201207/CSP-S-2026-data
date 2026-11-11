#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	if(x>y) return 0;
	else return 1;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,l,a[10005],b[10005];
	cin>>n>>l;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(n%2==0) n=n/2-1;
	else n=n/2;
	cout<<a[n];
}
