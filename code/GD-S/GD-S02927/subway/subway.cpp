#include <bits/stdc++.h>
#define cls(x) memset(x, 0, sizeof(x))

//#define printl(l,s) {printf( #l ); printf(" = ["); for (int i = 0;i<s;i++) printf("%d,",l[i]); printf("]\n");}
using namespace std;

const int N_MAX = 500;
//const int M_MAX = 500000;
const int M_MAX = 50000;
//const int Q_MAX = 100000;
//const long INF = 1l << (sizeof(long)-1);

int W[N_MAX];
int K[N_MAX];
int A[N_MAX][M_MAX];
int T[N_MAX][M_MAX];
int STA[M_MAX][21];

int TIME = 0;
void dfs(int e, int a, int *la, int las, int t){
	if (a==e) {
//		printf("[TIME = min(%d, %d)]", t, TIME);
		TIME = min(t,TIME);
		return;
	}
//	printf("[e:%d a:%d las:%d t:%d]", e,a,las,t);
//	printl(la, las);
	for (int i = 0;i<K[a];i++){
		for (int j = 0;j<20;j++){
			if (STA[A[a][i]][j]) {
				int an = STA[A[a][i]][j];
				char f = 0;
				for (int k = 0;!f&&k<las;k++){
//					printf("[la[k{%d}]{%d} == an{%d}]\n", k, la[k], an);
					if (la[k] == an) f = 1;
				}
				if (f) continue;
				la[las++] = an;
				int p = 0;for (;p<K[an];p++){
					if (A[an][p] == A[a][i]) break;
				}
				dfs(e, an, la, las, t+T[a][i]+T[an][p]);
				las--;
			}
		}
	} 
}


int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cls(STA);
	int c, n, m, d, q;
	scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
	for (int i = 0;i<m;i++){
		scanf("%d", &W[i]);
	}
	for (int i = 0;i<n;i++){
		scanf("%d", &K[i]);
		for(int j = 0;j<K[i];j++){
			scanf("%d %d", &A[i][j], &T[i][j]);
			for (int p = 0;p<20;p++) if (!STA[A[i][j]][p]) STA[A[i][j]][p] = i;
		}
	}
	
//	for (int i = 0;i<n;i++){
//		printl(STA[i], K[i]);
//	}
//	return 0;
	
	for (int i = 0;i<q;i++){
		int s,e;
		scanf("%d %d", &s,&e);
		int sa[20], ea[20];int sp=0, ep=0;
		for (int j = 0;j<20;j++){
			if (STA[s][j]) sa[sp++] = STA[s][j];
		}
		for (int j = 0;j<20;j++){
			if (STA[e][j]) ea[sp++] = STA[e][j];
		}
		int sap = 0, sep = 0;
		for (int j = 0;!sap&&j<K[sa[0]];j++){
			if (A[sa[0]][j] == s) sap = j;
		}
		for (int j = 0;!sep&&j<K[ea[0]];j++){
			if (A[ea[0]][j] == s) sep = j;
		}
		int bt = T[sa[0]][sap] + T[ea[0]][sep] + W[s] + W[e];
		
		TIME = 999999999;
		int la[N_MAX];la[0] = s;
		dfs(e,s,la,1,0);
		printf("%d\n", TIME + bt);
	}

	return 0;
} 
