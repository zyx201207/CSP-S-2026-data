#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	s=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		s&=a[i];
	}
	cout<<s;
	return 0;
}
