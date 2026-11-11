#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int r = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while('0' <= c && c <= '9') r = (r << 1) + (r << 3) + (c ^ '0'),c = getchar();
	return r;
}
inline long long readml(){
	long long r = 0;
	char c = getchar();
	bool flag = false;
	while((c < '0' || c > '9') && (c ^ '-')) c = getchar();
	(c == '-') && (c = getchar(),flag = true);
	while('0' <= c && c <= '9') r = (r << 1) + (r << 3) + (c ^ '0'),c = getchar();
	return flag ? -r : r;
}
inline void wr(long long x){
	if(!x){
		putchar('0');
		return;
	}
	static char buf[105];
	int cnt = 0;
	while(x) buf[++cnt] = (x % 10) ^ '0',x /= 10;
	while(cnt) putchar(buf[cnt--]);
}
int c,t,n;
long long x[2000005],d;
int ld[2000005],rd[2000005];
int pr[2000005],nx[2000005];
int pc[2000005],nc[2000005];
inline void sv(){
	n = read();d = readml();
	//if(n <= 100) puts("I love you");
	long long ans = 0;
	for(int i = 1;i <= n;i++) x[i] = readml(),ld[i] = rd[i] = pc[i] = nc[i] = 0;
	//for(int i = 1;i <= n;i++) printf("%lld ",x[i]);puts("");
	if(n <= 3){
		puts("0");
		return;
	}
	pr[1] = 1,pc[1]++;
	for(int i = 2,p = 1;i <= n;i++){
		while(x[i] - x[p] > d) p++;
		pr[i] = p;
		pc[p]++;
	}
	nx[n] = n,nc[n]++;
	for(int i = n - 1,p = n;i;i--){
		while(x[p] - x[i] > d) p--;
		nx[i] = p;
		nc[p]++;
	}
	//for(int i = 1;i <= n;i++) printf("%d %d\n",pr[i],nx[i]);
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			//printf(":%d %d\n",i,j);
			map<int,int> mp;
			mp[i]++,mp[j]++;
			int p = i;
			bool flag = false;
			while(p ^ j){
				int lp = p;
				p = min(nx[p],j);
				if(lp == p){
					flag = true;
					break;
				}
				mp[p]++;
			}
			if(flag) continue; 
			p = j;
			while(p ^ i){
				int lp = p;
				p = max(pr[p],i);
				if(lp == p){
					flag = true;
					break;
				}
				mp[p]++;	
			}
			if(flag) continue; 
			for(auto u : mp){
				if(u.second == 1){
					flag = true;
					break;
				}
			}
			if(flag) continue;
			ld[j]++;rd[i]++;
			//puts("success");
		}
	}
	for(int i = 2;i <= n - 2;i++){
		int aa = pr[i + 1];
		int dd = nx[i];
		if(nx[aa] != i + 1 || pr[dd] != i || aa >= i || dd <= i + 1) continue;
		//ans += (long long)pc[i] * nc[i + 1]; 
		long long pn = nc[i + 1],nn = pc[i];
		/*if(pr[i] < aa || nx[i + 1] > dd){
			
		}*/
		//printf("t%d %d\n",aa,nx[pr[aa]]);
		if(pr[i] >= aa && nx[pr[aa]] == aa) pn += ld[aa]/*,puts("o")*/;
		if(nx[i + 1] <= dd && pr[nx[dd]] == dd) nn += rd[dd]/*,puts("p")*/;
		
		
		ans += pn * nn;
		//printf("%d %d %d %d %lld %lld\n",aa,i,i + 1,dd,pn,nn);
		//ans += (long long)(nx[pr[aa]] == aa ? ld[aa] + 1 : 1) * (pr[nx[dd]] == dd ? rd[dd] + 1 : 1) - 1; 
	}
	wr(ans);putchar('\n');
}
inline void svA(){
	n = read();d = readml();
	//long long ans = 0;
	for(int i = 1;i <= n;i++) x[i] = readml();
	if(n <= 3){
		puts("0");
		return;
	}
	long long u = x[2] - x[1];
	long long bs = d / u;
	if(bs <= 1){
		puts("0");
		return;
	}
	else wr(max(0ll,n - 2 * bs + 1)),putchar('\n');
}
inline void svB(){
	n = read();d = readml();
	//if(n <= 100) puts("I love you");
	long long ans = 0;
	for(int i = 1;i <= n;i++) x[i] = readml(),ld[i] = rd[i] = pc[i] = nc[i] = 0;
	//for(int i = 1;i <= n;i++) printf("%lld ",x[i]);puts("");
	if(n <= 3){
		puts("0");
		return;
	}
	pr[1] = 1,pc[1]++;
	for(int i = 2,p = 1;i <= n;i++){
		while(x[i] - x[p] > d) p++;
		pr[i] = p;
		pc[p]++;
	}
	nx[n] = n,nc[n]++;
	for(int i = n - 1,p = n;i;i--){
		while(x[p] - x[i] > d) p--;
		nx[i] = p;
		nc[p]++;
	}
	int lp = -1,rp = -1;
	for(int i = 1;i <= n;i++){
		if(pr[i] == 1 && nx[i] == n){
			lp = i;
			break;
		}
	}
	for(int i = n;i;i--){
		if(pr[i] == 1 && nx[i] == n){
			rp = i;
			break;
		}
	}
	if(lp == -1 && rp == -1) goto normal;
	if(rp - lp + 1 >= 3){
		puts("0");
		return;
	}
	if(lp == 1 && rp == n){
		puts("0");
		return;
	}
	normal:for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			//printf(":%d %d\n",i,j);
			map<int,int> mp;
			mp[i]++,mp[j]++;
			int p = i;
			bool flag = false;
			while(p ^ j){
				int lp = p;
				p = min(nx[p],j);
				if(lp == p){
					flag = true;
					break;
				}
				mp[p]++;
			}
			if(flag) continue; 
			p = j;
			while(p ^ i){
				int lp = p;
				p = max(pr[p],i);
				if(lp == p){
					flag = true;
					break;
				}
				mp[p]++;	
			}
			if(flag) continue; 
			for(auto u : mp){
				if(u.second == 1){
					flag = true;
					break;
				}
			}
			if(flag) continue;
			ld[j]++;rd[i]++;
			//puts("success");
		}
	}
	for(int i = 2;i <= n - 2;i++){
		int aa = pr[i + 1];
		int dd = nx[i];
		if(nx[aa] != i + 1 || pr[dd] != i || aa >= i || dd <= i + 1) continue;
		//ans += (long long)pc[i] * nc[i + 1]; 
		long long pn = nc[i + 1],nn = pc[i];
		/*if(pr[i] < aa || nx[i + 1] > dd){
			
		}*/
		//printf("t%d %d\n",aa,nx[pr[aa]]);
		if(pr[i] >= aa && nx[pr[aa]] == aa) pn += ld[aa]/*,puts("o")*/;
		if(nx[i + 1] <= dd && pr[nx[dd]] == dd) nn += rd[dd]/*,puts("p")*/;
		
		
		ans += pn * nn;
		//printf("%d %d %d %d %lld %lld\n",aa,i,i + 1,dd,pn,nn);
		//ans += (long long)(nx[pr[aa]] == aa ? ld[aa] + 1 : 1) * (pr[nx[dd]] == dd ? rd[dd] + 1 : 1) - 1; 
	}
	wr(ans);putchar('\n');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),t = read();
	//c = 13;
	if(11 <= c && c <= 12) while(t--) svA();
	else while(t--) svB();
	return 0;
}
