#include <cstdio>
using namespace std;

int c, t;
int n, d;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &n, &t);
	while(t--){
		scanf("%d%d", &n, &d);
		printf("%d", n/d);
	}
	return 0;
}
