#include<bits/stdc++.h>
#define N 2000010
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define lowbit(x) (x&-x)
using namespace std;
int n,_,T,to[N];
ll d,a[N];
ll f[N][4];
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin >> _ >> T;
	while(T--){
		cin >> n >> d;
		int l = 1;// not put 
		ll ans = 0;
		for(int i = 1;i <= n;++i){to[i] = n;
			f[i][0] = f[i][1] = f[i][2] = f[i][3] = 0;
			cin >> a[i];
//			while(l != i && a[i] - a[l] > d)to[l] = i-1,++l;
//			while(l < n && a[l+1] - a[i] <= d)++l;
//			to[i] = l;
		}
		for(int i = 1;i <= n;++i){
			while(l < n && a[l+1] - a[i] <= d)++l;
			to[i] = l;
		}
//		for(int i = 1;i <= n;++i)printf("to[%d] = %d\n",i,to[i]);
//		printf("-----------\n");
		for(int i = n;i >= 1;--i){// beginner of to chain 
			if(to[i] == i)continue; 
			int ty = to[i];
			if(ty - i == 1){
				f[i][0] = f[ty][0];
				if(i >= 2 && to[i-1] == ty){
					if(i >= 3 && to[i-2] == ty);// death
					else f[i][1] = f[ty][2] + 1;
					f[i][2] = f[i][3] = 0;
				}else if(i >= 2 && to[i-1] == i){
					f[i][1] = f[ty][0];
					f[i][2] = f[ty][2] + 1;
					f[i][3] = f[ty][0];
				}else{
					f[i][1] = 0;
					f[i][2] = f[ty][2] + 1;
					f[i][3] = 0;
				}
				continue;
			}
			f[i][0] = f[ty][1];
			if(i >= 2 && to[i-1] == ty){
				int ty3;
				if(i >= 3 && to[i-2] == ty);// death
				else{
					if(i >= 3 && to[i-2] >= i)ty3 = to[i-2];
					else ty3 = i;
					f[i][1] = f[ty][2] + ty - ty3;
					f[i][2] = f[i][3] = 0;
				}
			}else if(i >= 2 && to[i-1] == ty-1){
				int ty3;
				if(i >= 3 && to[i-2] >= i)ty3 = to[i-2];
				else ty3 = i;
				f[i][1] = f[ty][3] + ty-1-ty3;
				f[i][2] = f[ty][2] + 1;
				f[i][3] = f[ty][3]; 
			}else if(i >= 2 && to[i-1] >= i){
				int ty2 = to[i-1],ty3;
				if(i >= 3 && to[i-2] >= i)ty3 = to[i-2];
				else ty3 = i;
				f[i][1] = f[ty][1] + ty2 - ty3;
				f[i][2] = f[ty][2] + ty - ty2;
				f[i][3] = f[ty][1];
			}else{// single 
				f[i][1] = f[i][3] = -INF;
				f[i][2] = f[ty][2] + ty - i;
			}
		}
		for(int i = 1;i <= n;++i){
			if(to[i] == i)continue;
			if(to[i] - i == 1)ans = ans + f[to[i]][0];
			else ans = ans + f[to[i]][1];
		}
		cout << ans << '\n';
	}
	
	
	return 0;
} 
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
