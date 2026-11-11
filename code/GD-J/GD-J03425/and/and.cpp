#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	maxx=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		maxx=a[i]&maxx;
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
