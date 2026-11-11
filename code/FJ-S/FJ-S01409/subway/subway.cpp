#include<bits/stdc++.h>

using namespace std;

// n线路数，m地铁站数,d每个地铁站经过的地铁数 
int c,n,m,d,q;
int subPointsA[500100];
// 点坐标 
//前500 000地铁站，后500地铁线路 
int table[510][500100];

int END;

long long bfsANS = 0;

bool jingguo[510][500100];
long long dfs(int last) {
	if (last == END) {
		return 0;
	}
	int countSubway = 0;
	long long price = -1;
	//先从地铁站到地铁 
	for (int i =1;i<=n;i++) {
		if (table[i][last] == -1) continue;
		if (countSubway > d) break;
		countSubway++;
		if (jingguo[i][last]) continue;
		jingguo[i][last] = true; 
		
		
		// 再从地铁到地铁站
		int countPoint = 0; 
		for (int j = 1;j<=m;j++) {
			if (table[i][j] == -1) {
				continue; 
			}
			if (countPoint > table[i][0]) break;
			countPoint++;
			if (jingguo[i][j]) continue;
			jingguo[i][j] = true;
			int input = dfs(j);
			if (input == -1) {
				continue;
			}
			
			long long MS = table[i][last] + table[i][j] + input;
			if (price==-1) {
				price=MS;
			} else {
				price = min(price,MS);
			}
			jingguo[i][j] = false;
		}
		jingguo[i][last] = false;
	}
	return price;
}

bool bfs(int depth,int last) {
	int countSubway = 0;
	//先从地铁站到地铁 
	for (int i =1;i<=n;i++) {
		if (table[i][last] == -1) continue;
		if (countSubway > d) break;
		countSubway++;
		
		// 再从地铁到地铁站
		if (table[i][END] != -1) {
			bfsANS = (depth+1)*2*table[i][END];
			jingguo[i][0] = false;
			return true;
		} 
	}
	countSubway = 0;
	for (int i = 1;i<=n;i++) {
		// 再从地铁到地铁站
		if (table[i][last] == -1) continue;
		if (countSubway > d) break;
		countSubway++;
		if (jingguo[i][0]) continue;
		jingguo[i][0] = true;  
		
		int countPoint = 0; 
		for (int j = 1;j<=m;j++) {
			if (table[i][j] == -1) {
				continue; 
			}
			if (countPoint > table[i][0]) break;
			countPoint++;
			if (bfs(depth+1,j)) {
			  jingguo[i][0] = false;
			  return true;
			}
		}
		jingguo[i][0] = false;
	}
	return false;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(&table,-1,sizeof(table));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 1;i<=m;i++) {
		scanf("%d",subPointsA+i);
	}
	for (int i = 1;i<=n;i++) {
		scanf("%d",&table[i][0]);
		for (int j = 1;j<= table[i][0];j++) {
			int end,value;
			scanf("%d%d",&end,&value);
			table[i][end] = value; 
		}
	}
	if (12<=c&&c<=19) {
		for (int i = 1;i<=q;i++) {
			int sP,eP;
			scanf("%d%d",&sP,&eP);
			END = eP;
			bfs(0,sP);
			long long ans = bfsANS + ((long long)subPointsA[sP] +subPointsA[eP]);
			cout << ans << '\n'; 
		} 
		return 0;	
	}
	for (int i = 1;i<=q;i++) {
		int sP,eP;
		scanf("%d%d",&sP,&eP);
		END = eP;
		dfs(sP);
		long long ans = dfs(sP) + ((long long)subPointsA[sP] +subPointsA[eP]);
		cout << ans << '\n'; 
	} 
	return 0;
}
