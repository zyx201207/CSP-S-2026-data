#include <cstdio>
#include <algorithm>
#define N 2000005
#define ll long long
using namespace std;

int C, T;
int n, i, j, k;
int p[N], q[N], l[N], r[N], ed;
ll d, a[N], ans, s[N], t[N], x, y;
int nxt(int x){
	if(x < 1)	return 1;
	return upper_bound(a+1, a+1+n, a[x]+d)-a-1;
}
int prv(int x){
	if(x > n)	return n;
	return lower_bound(a+1, a+1+n, a[x]-d)-a;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &C, &T);
	while(T--){
//		puts("\n\n\nT");
		ans = 0;
		scanf("%d%lld", &n, &d);
		for(i=1; i<=n; i++)	scanf("%lld", a+i);
		for(i=1; i<=n; i++)	r[i] = nxt(i);
		if(C <= 10){
			for(i=1; i<=n; i++){
				ed = n+1;
				for(j=i; j<=n; ){
					l[p[j]+1] = j+1; 
					for(k=j+1; k <= n && a[k]-a[j] <= d; k++)	p[k] = p[j]+1;
					if(r[j] == j){
						ed = k;
						break;
					}
					j = k-1;
				}	//pj:j与i的长度
				//lp:长度为p的第一个位置 
				t[i] = 1, t[i+1] = -1;
				for(j=i; j<ed; j++){
					t[j] += t[j-1];	//差分 
					if(t[j] == 2)	ans++;
					t[l[p[j]+1]] += t[j];
					t[r[j]+1] -= t[j];
				} 
				for(j=1; j<=n; j++)	p[j] = q[j] = s[j] = t[j] = 0; 
			}
			for(i=0; i<=n+1; i++)	p[i] = q[i] = s[i] = t[i] = 0;
		}
		else if(C <= 12){
			ll f = a[2]-a[1];
			if(d >= f*2 && d < f*3)	printf("%d\n", max(0, n-3));
			else	printf("0\n");
			continue;
		}
		else if(C <= 14){
			for(i=1; i<=n; i++){
				if(r[i] > 2){
					x = r[r[i]-2], y = r[r[i]-1];
					ans += y-x;
				}
			}
		}
		else if(C <= 18){
			
		}
		printf("%lld\n", ans);
	}
	return 0;
}

/*似 
#include <cstdio>
#include <algorithm>
#define N 2000005
#define ll long long
using namespace std;

int C, T;
int n, i, f, t, l, r;
int p[N], p1[N], p2, q[N];
ll d, a[N], ans;
int nxt(int x){
	if(x < 1)	return 1;
	return upper_bound(a+1, a+1+n, a[x]+d)-a-1;
}
int prv(int x){
	if(x > n)	return n;
	return lower_bound(a+1, a+1+n, a[x]-d)-a;
}
int main(){
	freopen("migrate6.in", "r", stdin);
	scanf("%d%d", &C, &T);
	while(T--){
//		printf("T%d\n", T); 
		ans = 0;
		scanf("%d%lld", &n, &d);
		for(i=1; i<=n; i++)	scanf("%lld", a+i);
		for(i=n; i; i--){
			f = nxt(i);
			p1[i] = min(f, n)-i;
			p2 = nxt(f)-nxt(f-1);
			p[i] = p1[i] + p2;
			if(p2)	p[i] += p[f]-p1[f];
			//距离为2的单路径(nxt(f-1), nxt(f)]
		}
		for(i=1; i<=n; i++){
			f = prv(i);
			p1[i] = i - f;
			p2 = prv(f+1)-prv(f);
			q[i] = p1[i] + p2;
			if(p)	q[i] += q[f]-p1[f];
		}
//		for(i=1; i<=n; i++){
//			printf("%d prev %d next %d\n", a[i], q[i], p[i]);
//		}
		for(i=1; i<=n-3; i++){
			f = nxt(i);
			if(f-i < 2)	continue;
			l = nxt(f-2), r = nxt(f-1), t = nxt(f);
			l = max(l, f);
			if(r == l)	continue;
			if(f > 2 && 1){
				f = q[i] - max(0, i-prv(i+1));
//				printf("a%lld LR(%d %d)\n", a[i], a[l], a[r]);
//				printf("qi%d prv %d\n", q[i], q[i] - max(0, i-prv(i+1))+1);
				ans += 1ll * (p[r]-max(0, nxt(r-1)-r)+1) * (q[i] - max(0, i-prv(i+1))+1);
				ans += r-l-1;
//				printf("ans%lld\n", ans);

//				ans += 1ll * (p[r] - max(0, nxt(r-1)-r)) * (q[i] - max(0, i-prv(i+1)));
//				ans += r-l;
//				printf("a%lld ans%lld L%d R%d\n", a[i], ans, l, r);
			}
			//(l, r] 距离为2的 
		}
		printf("%lld\n", ans);
		for(i=1; i<=n; i++)	p[i] = p1[i] = q[i] = 0;
	}
}
*/
