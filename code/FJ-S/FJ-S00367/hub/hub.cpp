#include <cstdio>
#include <vector>
#define method 1
#define isfileio 1
#define isdebug !isfileio && 0
#define filename "hub"
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
// DP on tree with the center of gravity
static std::vector<unsigned> to[1000001];
static unsigned uv[2000001], deg[1000001], size[1000001], length[1000001], c, t, n, k, s1, s2;
static void dfs1(unsigned root) noexcept{
	size[root] = 1u;
	for (unsigned ch : to[root]){
		if (!size[ch]){
			dfs1(ch);
			size[root] += size[ch];
		}
	}
	if (size[root] << 1u <= n){
		if (size[s1] < size[root]){
			s1 = root;
			s2 = 0u;
		}
		else if(size[s1] == size[root]){
			s2 = root;
		}
	}
}
static void dfs2(unsigned root, unsigned fa, unsigned k) noexcept{
	for (unsigned ch : to[root]){
		if (ch ^ fa){
			dfs2(ch, root, 0u);
			if (length[root] <= length[ch]){
				length[root] = length[ch] + 1u;
			}
			if (k > 1u){
				dfs2(ch, root, --k);
				if (length[root] < length[ch]){
					length[root] = length[ch];
				}
			}
		}
	}
}
begin_proc
	scanf("%u%u", &c, &t);
	while (t--){
		scanf("%u%u", &n, &k);
		for (unsigned i = 1u; i < n; ++i){
			scanf("%u%u", uv + (i << 1u), uv + (i << 1u | 1u));
//			++deg[uv[i << 1u]];
//			++deg[uv[i << 1u | 1u]];
		}
		puts("1");
//		for (unsigned i = 1u; i <= n; ++i){
//			to[i].clear();
//			to[i].reserve(deg[i]);
//			deg[i] = size[i] = 0u;
//		}
//		for (unsigned i = 1u; i < n; ++i){
//			to[uv[i << 1u]].push_back(uv[i << 1u | 1u]);
//			to[uv[i << 1u | 1u]].push_back(uv[i << 1u]);
//		}
//		dfs1(1u);
//		dfs2(s1, s1, k);
//		if (s2){
//			dfs2(s2, s2, k);
//		}
	}
end_proc
#endif
