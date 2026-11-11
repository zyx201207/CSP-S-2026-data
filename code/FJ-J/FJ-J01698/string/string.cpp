#include<bits/stdc++.h>
using namespace std;
int n;
long long ft, ed, sum;
char f, d;
struct sr{
	int sl;
	char zf;
}e[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> e[i].sl >> e[i].zf;
	}
	for(int i = 1, j = n; i <= j;){
		if(ft == 0){
			ft += e[i].sl;
			f = e[i].zf;
			i+=1;
		}
		if(ed == 0){
			ed += e[j].sl;
			d = e[j].zf;
			j-=1;
		}
		if(ft>=ed){
			if(f != d){
				sum += ed;
			}
			ft -= ed;
			ed = 0;
		}else{
			if(f != d){
				sum+=ft;
			}
			ed -= ft;
			ft = 0;
		}
	}
	cout << sum;
	return 0;
}