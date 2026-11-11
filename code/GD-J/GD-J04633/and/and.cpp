//and
#include <stdio.h>
#include <vector>
int n, m;
unsigned long long a[214514];
std::vector<unsigned long long> v;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int i, j;
	for(i = 1; i <= n; i += 1) {
		scanf("%llu", &a[i]);
		v.push_back(a[i]);
	}
	unsigned long long final = 0;
	for(i = 31; i >= 0; i -= 1) {
		int bit_count = 0;
		for(j = 0; j < v.size(); j += 1) {
			bit_count += ((v[j] >> i) & 1);
		}
		if(bit_count >= m) {
			final |= (1 << i);
			for(j = 0; j < v.size(); j += 1) {
				if(((v[j] >> i) & 1) == 0) {
					std::swap(v[j], v[v.size() - 1]);
					v.pop_back();
					j -= 1;
				}
			}
		}
	}
	printf("%lld\n", final);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
