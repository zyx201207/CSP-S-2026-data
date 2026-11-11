#include <bits/stdc++.h>
#define cls(x) memset(x, 0, sizeof(x))
//#define printl(l,s) {printf( #l ); printf(" = ["); for (int i = 0;i<s;i++) printf("%d,",l[i]); printf("]\n");}

using namespace std;



int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c ,t;
	scanf("%d %d", &c, &t);
	for(int i = 0;i<t;i++){
		int n,d;
		scanf("%d %d", &n, &d);
		int X[n],D[n],C[n];cls(C);
		for (int j = 0;j<n;j++){
			scanf("%d", &X[j]);
		}
		memset(D, 0x7f,sizeof(D));
		D[0] = 0;
		for (int j = 0;j<n;j++){
			for (int k = j+1;k<n;k++){
				if (X[k] - X[j] <= d) {
//					printl(C, n);printl(D, n);
//					printf("[%d == %d + 1]\n", D[k], D[j]);
					if(D[k] == D[j] + 1) {
//						printf("[%d]\n", k);
						C[k]++;
					}else if (D[k] > D[j] + 1){
//						printf("[%d][%d]\n", k, j);
						D[k] = D[j] + 1; 
						C[k] = 1;
					}
				}else break;
			}
		}
		

		int ans = 0;
		
		for (int j = 0;j<n;j++){
			for (int k = j+1;k<n;k++){
				ans += abs(C[k]-C[j]) == 2;
			}
			
		}
		printf("%d\n", ans);
//		puts("\n--------\n");
	} 
	
	return 0;
} 
