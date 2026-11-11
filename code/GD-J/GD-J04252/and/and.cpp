#include <cstdio>
#include <set>
#define N 200005
#define M 31
using namespace std;

int n, m, a[N], i, j, ans, f, s;
multiset<int> q;
set<int> er;
int main(){
	//rp++
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", a+i);
		q.insert(a[i]);
	}
	for(j=M-1; j>=0; j--){
		s = 0;
		for(int k:q){
			if(k & 1<<j)	s++;
		}
		if(s >= m){
			er.clear();
			for(int k:q){
				if((k & 1<<j) == 0)	er.insert(k);
			}
			for(int k:er)	q.erase(k);
		}
	}
	ans = -1;
	for(int k:q)	ans &= k;
	printf("%d", ans);
	return 0;
}	//xw
