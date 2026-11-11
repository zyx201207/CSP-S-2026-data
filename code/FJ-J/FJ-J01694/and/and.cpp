#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int a[2000020];
	for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
	}
	cout << a[n];
	return 0;
}
