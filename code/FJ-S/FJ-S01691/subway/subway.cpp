#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef DEBUG
#define DB_PRINT_VEC(VEC) do{for(const auto &i: VEC)cout<<i<<"|"; cout<<endl;}while(0)
#define DB_PRINT(STH) cout << STH
#else
#define DONOOP do{}while(0)
#define DB_PRINT_VEC(VEC) DONOOP
#define DB_PRINT(STH) DONOOP
#endif

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);


}