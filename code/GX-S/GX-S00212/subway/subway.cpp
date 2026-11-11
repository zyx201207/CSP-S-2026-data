#include <stdio.h>
using namespace std;

struct timeLK{
	short s;
	int t;
};

struct TT{
	short l;
	int t;
};

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, n, m, d, q;
	scanf("%d", &c);//useless
	scanf("%d", &n);//lines
	scanf("%d", &m);//stations
	scanf("%d", &d);//passed?
	scanf("%d", &q);//missions
	
	int timefromkou[m+5];//time from kou
	int G[n][n];//graph
	timeLK tlk[n][m];//time line kou
	TT linetokou[m+1][d];//di n ge kou dao de line num and its time
	int linesofkou[m+5];
	
	//printf("yes");//test
	//station is normal, but lines -=1
	//input graph
	for(int i = 0; i < m; i++){
		scanf("%d", &timefromkou[i+1]);
		linesofkou[i+1] = 0;
	}
	for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)tlk[i][j].s = -1;
	for(int I = 0; I < n; I++){//lines
		int k;
		scanf("%d", &k);
		for(int i = 0; i < k; i++){//station of line
			int a, t;//station, time
			scanf("%d", &a);
			scanf("%d", &t);
			tlk[I][i].s = a, tlk[I][i].t = t;
			linetokou[a][linesofkou[a]].l = I, linetokou[a][linesofkou[a]++].t = t;
		}
	}
	//create graph
	for(int a = 0; a < n; a++)for(int b = 0; b <= a; b++){
		if(a == b){
			G[a][b] = 0; continue;
		}
		int pa = 0, pb = 0, min = 300000000;
		while(pa < m && pb < m){
			//prlong long intf("pa%i pb%i ", pa, pb);
			if(tlk[a][pa].s == -1 || tlk[b][pb].s == -1)break;
			if(tlk[a][pa].s == tlk[b][pb].s){
				int temp = tlk[a][pa++].t + tlk[b][pb++].t;
				if(temp < min)min = temp;
			}
			else if(tlk[a][pa].s > tlk[b][pb].s)pb++;
			else pa++;
		}
		G[a][b] = G[b][a] = min;
		//printf("%i ", G[a][b]);//test
	}
	//floyd
	for(int a = 0; a < n; a++)for(int b = 0; b <= a; b++)for(int c = 0; c < n; c++){//from a to b passing c
		if(a == b || a == c || b == c)continue;
		int temp = G[a][c] + G[c][b];
		if(G[a][b] > temp)G[a][b] = G[b][a] = temp;
		//prlong long intf("%i ", G[a][b]);
	}
	//for(long long int a = 0; a < n; a++)for(long long int b = 0; b < n; b++)prlong long intf("%i ", G[a][b]);//test
	//solve missions
	for(int l = 0; l < q; l++){
		int x, y, ans;
		scanf("%d", &x);//start
		scanf("%d", &y);//end
		ans = timefromkou[x] + timefromkou[y];
		int min = 300000000;
		for(int a = 0; a < linesofkou[x]; a++)for(int b = 0; b < linesofkou[y]; b++){
			//prlong long intf("%i\n", linetokou[y][b].l);//test
			int temp = G[linetokou[x][a].l][linetokou[y][b].l];
			temp += linetokou[x][a].t + linetokou[y][b].t;
			if(temp < min)min = temp;
			//prlong long intf("%i\n", temp);//test
		}
		ans += min;
		printf("%i\n", ans);
	}
	return 0;
}
