#include <algorithm>
#include <cstdio>
#define isfileio 1
#define filename "crystal"
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
// double pointer from least to greatest
static unsigned long long a[500001], m;
static long long x;
static unsigned n, ans;
begin_proc
	scanf("%u%llu", &n, &m);
	for (unsigned i = 0u; i < n; ++i){
		scanf("%lld", &x);
		a[i] = (unsigned long long)(x + 1000000000000ll);
	}
	std::sort(a, a + n);
	for (unsigned i = 0u, j = 1u; j < n; ++i){
		if (j == i){
			++j;
		}
		while (j < n && m >= (a[j] - a[j - 1u]) * (j - i)){
			m -= (a[j] - a[j - 1u]) * (j - i);
			++j;
		}
		if (ans < j - i){
			ans = j - i;
		}
		m += a[j - 1u] - a[i];
	}
	printf("%u", ans);
end_proc
