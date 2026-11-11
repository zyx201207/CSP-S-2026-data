#include <bits/stdc++.h>
#define crls(x) memset(x,0,sizeof(x));

using namespace std;

int table[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	scanf("%d %d", &n, &m);
	int A[n];
	for (int i = 0;i<n;i++){
		scanf("%d", &A[i]);A[i]--;
	}
	
	int lc[m];crls(lc);
	char vis[m];
	for (int i = 0;i<n;i++){
		crls(vis);
		int pos = 0;
		for(int p = i;p<n;p++){
			table[pos] = A[p];
			if(vis[A[p]]){
				if (vis[A[p]]==-1){
					pos = 0;
					crls(vis);
					vis[A[p]] = -1;
				}else for(pos--;pos>vis[A[p]];pos--){
					vis[table[pos]] = 0;
				}
				vis[A[p]] = pos?pos:-1;
			}else{
				vis[A[p]] = pos?pos:-1;
			}
			pos++;
		}
		for(pos--;pos>=0;pos--){
			lc[table[pos]]++;
		}
	}
	for (int i = 0;i<m;i++){
		printf("%d ", lc[i]);
	}
	
	return 0;
} 
// 4 3 1 2 1 3
// 10 3 3 1 2 1 3 2 3 1 2 1
// 10 3 2 0 1 0 2 1 2 0 1 0












