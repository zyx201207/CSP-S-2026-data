#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100],i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=m;j++){
			a[i]=a[i] and a[i];
		}
	}
	sort(a+1,a+n+1);
	fclose(stdin);
	fclose(stdout);
	cout<<i;
	return 0;
}