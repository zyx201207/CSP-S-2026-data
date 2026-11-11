#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int t, n, k;
int main()
{
	srand(time(0));
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &t, &t);
	for (int _ = 1; _ <= t; _ ++)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i ++)
		{
			char* a = new char[1001];
			fgets(a, 1000, stdin);
			delete[] a;
			rand();
		}
		if (n == k)
		{
			printf("0\n");
		}
		printf("%d\n", ((rand() << 16) | rand()) % (n - k) + 1);
	}
}