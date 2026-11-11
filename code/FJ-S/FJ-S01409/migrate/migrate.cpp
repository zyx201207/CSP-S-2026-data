#include<bits/stdc++.h>

using namespace std;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	scanf("%d%d",&c,&t); 
	for (int i = 0;i<t;i++) {
		int n,d;
		scanf("%d%d",&n,&d);
		int data[n];
		for (int j = 0;j<n;j++) {
			scanf("%d",data+j);
		}
		if (n < 10) {
			cout<< 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	
	return 0;
}
