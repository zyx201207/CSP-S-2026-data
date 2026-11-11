#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5+10;
struct ysh{
	int a;
	char b;
}e[N];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> e[i].a >> e[i].b;
	int pos1 = 1,pos2 = n;
	while (pos2 > pos1){
		if (e[pos1].b == e[pos2].b){
			if (e[pos1].a > e[pos2].a) {
				e[pos1].a -= e[pos2].a;
				pos2--;
			}else if (e[pos1].a < e[pos2].a){
				e[pos2].a -= e[pos1].a;
				pos1++;
			}else{
				pos1++;
				pos2--;
			}
		}else{
			if (e[pos1].a > e[pos2].a) {
				sum+=e[pos2].a;
				e[pos1].a -= e[pos2].a;
				pos2--;
			}else if (e[pos1].a < e[pos2].a){
				sum += e[pos1].a;
				e[pos2].a -= e[pos1].a;
				pos1++;
			}else{
				sum += e[pos1].a;
				pos1++;
				pos2--;
			}
		}
	}
	cout << sum;
}
