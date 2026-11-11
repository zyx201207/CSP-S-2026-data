#include <cstdio>
#define method 1
#define isfileio 1
#define isdebug !isfileio && 0
#define filename "subway"
#define begin_main int main() noexcept{
#define exit_main return 0
#define end_main }
#if isfileio
#define begin_proc begin_main \
	freopen(filename ".in", "r", stdin); freopen(filename ".out", "w", stdout);
#define exit_proc fclose(stdin); fclose(stdout); exit_main
#else
#define begin_proc begin_main
#define exit_proc exit_main
#endif
#define end_proc exit_proc; end_main
#if method == 1
// Floyd with mapping stations
static unsigned long long sp[501][501];
static unsigned w[500001], a[500001], t[500001], to[500001], where[500001], d[500001], k[501], c, n, m, q, x, y, md;
#if isdebug
static void show1() noexcept{
	puts("line:");
	for (unsigned i = 1u, j = 0u; i <= n; ++i){
		printf("%u:", i);
		for (; j < k[i]; ++j){
			printf(" (%u,%u)", a[j], t[j]);
		}
		putchar(10);
	}
	puts("station:");
	for (unsigned i = 1u, j = 0u; i <= m; ++i){
		printf("%u:", i);
		for (; j < d[i]; ++j){
			printf(" (%u,%u)", to[j], where[j]);
		}
		putchar(10);
	}
	putchar(10);
}
static void show2() noexcept{
	puts("line change:");
	for (unsigned i = 1u; i <= n; ++i){
		for (unsigned j = 1u; j <= n; ++j){
			printf("%llu ", sp[i][j]);
		}
		putchar(10);
	}
	putchar(10);
}
#define printdebug(...) printf(__VA_ARGS__)
#else
#define show1()
#define show2()
#define printdebug(...)
#endif
begin_proc
	scanf("%u%u%u%*u%u", &c, &n, &m, &q);
	for (unsigned i = 1u; i <= m; ++i){
		scanf("%u", w + i);
	}
	for (unsigned i = 1u, j = 0u; i <= n; ++i){
		scanf("%u", k + i);
		k[i] += k[i - 1u];
		for (; j < k[i]; ++j){
			scanf("%u%u", a + j, t + j);
			++d[a[j]];
		}
	}
	for (unsigned i = 1u; i <= m; ++i){
		if (md < d[i]){
			md = d[i];
		}
		d[i] += d[i - 1u];
	}
	for (unsigned i = 1u, j = 0u; i <= n; ++i){
		for (; j < k[i]; ++j){
			to[d[a[j] - 1u]] = i;
			where[d[a[j] - 1u]++] = j;
		}
	}
	for (unsigned i = m; --i; ){
		d[i] = d[i - 1u];
	}
	*d = 0u;
	show1();
	for (unsigned i = 1u; i <= n; ++i){
		for (unsigned j = 1u; j < i; ++j){
			sp[i][j] = 0x7fffffffffffffffllu;
		}
		for (unsigned j = i + 1u; j <= n; ++j){
			sp[i][j] = 0x7fffffffffffffffllu;
		}
	}
	for (unsigned i = 1u, j = 0u; i <= m; ++i){
		for (; j < d[i]; ++j){
			for (unsigned l = j + 1u; l < d[i]; ++l){
				if (sp[to[j]][to[l]] > t[where[j]] + t[where[l]]){
					sp[to[j]][to[l]] = sp[to[l]][to[j]] = t[where[j]] + t[where[l]];
				}
			}
		}
	}
	for (unsigned l = 1u; l <= n; ++l){
		for (unsigned i = 1u; i <= n; ++i){
			for (unsigned j = 1u; j <= n; ++j){
				if (sp[i][j] > sp[i][l] + sp[l][j]){
					sp[i][j] = sp[i][l] + sp[l][j];
				}
			}
		}
	}
	show2();
	while (q--){
		unsigned long long ans = ~0llu;
		scanf("%u%u", &x, &y);
		for (unsigned i = d[x - 1u]; i < d[x]; ++i){
			for (unsigned j = d[y - 1u]; j < d[y]; ++j){
				unsigned long long res = t[where[i]] + t[where[j]] + sp[to[i]][to[j]];
				if (res < ans){
					ans = res;
				}
				printdebug("(%u,%u) %llu (%u,%u)\n", to[i], t[where[i]], sp[to[i]][to[j]], to[j], t[where[j]]);
			}
		}
		printf("%llu\n", ans + w[x] + w[y]);
	}
end_proc
#endif
