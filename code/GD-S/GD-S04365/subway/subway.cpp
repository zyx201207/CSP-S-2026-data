#include <bits/stdc++.h>
using namespace std;

struct Station{
	int a;
	int t;
};

struct Way{
	int x;
	int y;
};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	
	int w[m + 1];
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	
	int k[n + 1];
	Station at[500001];
	int tmp = 0;
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> at[j + tmp].a >> at[j + tmp].t;
		}
		tmp += k[i];
	}

	Way xy[q + 1];
	for(int i = 1;i <= q;i++){
		cin >> xy[i].x >> xy[i].y;
	}
	
	int ans;
	for(int z = 1;z <= q;z++){
		ans = w[xy[z].x] + w[xy[z].y];
		
		int change;
		int start;
		int end;
		for(int i = 1;i <= k[1];i++){
			if(at[i].a == xy[z].x){
				start = i;
			}
			for(int j = 1;j <= k[2];j++){
				if(at[i].a == at[k[1] + j].a){
					change = at[i].a;
					ans += at[i].t;
					ans += at[k[1] + j].t;
				}
				
				if(at[k[i] + j].a == xy[z].y){
					end = k[i] + j;
				}
			}
			
			for(int i = start;i < change;i++){
				ans += at[i].t;
			}
			for(int i = change + 1;i <= end;i++){
				ans += at[i].t;
			}
		}
	}
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
