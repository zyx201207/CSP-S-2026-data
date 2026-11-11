//GZ-J00168 遵义市第四中学 陈律金 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	cout<<a[n-m];
	fclose(stdin);
	fclose(stdout);
}

