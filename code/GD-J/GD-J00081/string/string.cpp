#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long x,cnt = 0;
	cin >> n;
	char c;
	long long k = 0;
	long long l[220000] = {};
	char lc[220000] = {};
	while(n --){
		cin >> x >> c;
		if(lc[k] == c){
			l[k] += x;
		}
		else{
			lc[++ k] = c;
			l[k] = x;
		}
	}
	if(k == 1) cnt = 0;
	else{
		long long lt = 1,rt = k;
		while(lt < rt){
			long long a = l[lt];
			char ta = lc[lt];
			long long b = l[rt];
			char tb = lc[rt];
			if(ta == tb){
				if(a == b){
					l[lt ++] = 0;
					l[rt --] = 0;
				}
				else if(a > b){
					l[lt] -= l[rt];
					l[rt] = 0;
					rt --;
				}
				else if(a < b){
					l[rt] -= l[lt];
					l[lt] = 0;
					lt ++;
				}
			}
			else{
				if(a == b){
					cnt += a;
					l[lt ++] = 0;
					l[rt --] = 0;
				}
				else if(a > b){
					cnt += a - b;
					l[lt] -= l[rt];
					l[rt] = 0;
					rt --;
				}
				else if(a < b){
					cnt += b - a;
					l[rt] -= l[lt];
					l[lt] = 0;
					lt ++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
