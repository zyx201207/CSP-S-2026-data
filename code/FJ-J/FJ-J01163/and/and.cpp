#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	int max_k=0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			int ant=1,max_num=a[i];
			for(int s=0;s<n;s++) {
				max_num=max_num&a[j+s];
				ant++;
				if(ant==m) break;
			}
			if(max_num>=max_k) max_k=max_num;
		}
		
	}
	printf("%d",max_k);
	return 0;
}
