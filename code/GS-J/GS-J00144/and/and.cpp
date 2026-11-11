#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.out","w",stdout);
	freopen("and.in","r",stdin);
	int n,m,b,c,l;
	cin>>n>>m;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	b=100000;
	for (int i=0;i<n;i++){
		if (b>a[i]){
			b=a[i];
			c=i;
		}
	}
	a[c]=100000;
	l=100000;
	for (int i=0;i<n;i++){
		if (l>a[i]){
			l=a[i];
		}
	}
	cout<<l;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
