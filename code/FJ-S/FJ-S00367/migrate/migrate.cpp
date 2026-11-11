#include <cstdio>
#define method 1
#define isfileio 1
#define isdebug !isfileio && 0
#define filename "migrate"
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
static unsigned long long x[2000001];
static unsigned l[2000001], r[2000001], sp[2000001];
static unsigned long long d;
static long long xx;
static unsigned c, t, n;
//static unsigned long long devide_apart(unsigned u, unsigned v) noexcept{
//	if (u + 4u > v){
//		return 0llu;
//	}
//	unsigned m = u + v >> 1u;
//	unsigned long long ret = devide_apart(u, m) + devide_apart(m, v);
//	for (unsigned i = m < u + 3u ? m : u + 3u; i < v; ++i){
//	}
//	return ret;
//}
static unsigned long long johnson() noexcept{ // 40pts
	unsigned long long ret = 0llu;
	for (unsigned i = 0u; i < n; ++i){
		sp[i] = 0u;
		for (unsigned j = i + 1u; j < n; ++j){
			sp[j] = 4294967294u;
		}
		for (unsigned j = i; j < n; ++j){
			l[j] = 1u;
		}
		for (unsigned j = i; j < n; ++j){
			if (l[j] == 2u){
				++ret;
			}
			for (unsigned k = j + 1u; k < r[j]; ++k){
				if (sp[j] + 1u < sp[k]){
					sp[k] = sp[j] + 1u;
					l[k] = l[j];
				}
				else if(sp[j] + 1u == sp[k]){
					l[k] += l[j];
				}
			}
		}
	}
	return ret;
}
begin_proc
	scanf("%u%u", &c, &t);
	while (t--){
		scanf("%u%llu", &n, &d);
		for (unsigned i = 0u; i < n; ++i){
			scanf("%lld", &xx);
			x[i] = (unsigned long long)(xx + 1000000000000000000ll);
		}
		for (unsigned i = 0u, j = 1u; i < n; ++i){
			while (j < n && x[j] <= x[i] + d){
				++j;
			}
			r[i] = j;
		}
//		for (unsigned i = n, j = n; i--; ){
//			while (j && x[j - 1u] >= x[i] - d){
//				--j;
//			}
//			l[i] = j;
//		}
//		printf("%llu\n", devide_apart(0u, n));
//		if (n < 5001u){
			printf("%llu\n", johnson());
//		}
	}
end_proc
#endif
