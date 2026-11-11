#include <bits/stdc++.h>
#define crls(x) memset(x,0,sizeof(x));

using namespace std;
int bits[32];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d", &n, &m);
	int A[n];
	for (int i = 0;i<n;i++){
		scanf("%d", &A[i]);
	}
	
	crls(bits);
	for(int i =0;i<n;i++){
		int p = A[i];
		while (p){
			int q = p&(-p), qi=0;
			while (q>0) {
				q/=2;qi++;
			}
			bits[qi-1]++;
			p = p&(p-1);
		}
	}
	
	int ans1 = 0;
	if(1){
		int vis[m], vi=0;crls(vis);
		for(int i = 0;i<m;i++){
			int mx = 0;
			for (int j = 0;j<31;j++){
				char f = 1;
				for (int k = 0;f&&k<vi;k++) if (vis[k] == j) f = 0;
				if (f && bits[j] > bits[mx]) mx = j; 
			}
			vis[vi] = mx;vi++;
			ans1 += 1<<mx;
		}
	}
	printf("%d", ans1);
	
	return 0;
} 
// 4 2 3 15 12 12
// 5 3 31 3 1 15 7
