#include<bits/stdc++.h>
using namespace std;
int n,m,mx,s1,s2;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[500005];
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	} sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
	    s1=0,s2=0;
		for(int j=i;j>=1;j--) {
			if(s1+(a[i]-a[j])<=m) {
				s1+=a[i]-a[j];
				s2++;
			} 
			else break;
		} mx=max(mx,s2); 
	} cout<<mx;
	//return 0;
	fclose(stdin);
	fclose(stdout);
}
