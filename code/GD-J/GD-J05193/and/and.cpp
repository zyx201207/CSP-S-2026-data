#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
__int32 a[N+5];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	__int32 ma=-1,c;
	for(int i=n;i>=m+1;i--){
		c=a[i];
		for(int j=i-1;j>=i-m+1;j--){
			c=c&a[j];
		}
		ma=max(ma,c);
	}
	cout<<ma;
	return 0;
}
