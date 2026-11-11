#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	maxx=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		maxx=maxx&a[i];
	}
	cout<<maxx<<endl;
	return 0;
}
