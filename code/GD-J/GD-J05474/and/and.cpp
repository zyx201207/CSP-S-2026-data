#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
