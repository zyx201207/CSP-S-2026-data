#include<bits/stdc++.h>
using namespace std;



#define LEN (int)(2*(1e5))+5
uint32_t ns[LEN],ldts[LEN];
int n,m;
unsigned long long ls[LEN];
int collect_1_num(int bit){
	bit = 32 - bit;
	int cnt = 0;
	for (int i=0;i<n;i++) {
		if ((ns[i] << (32-bit)) >> 31 == 1) {
			cnt++;
			ls[i] += bit*10;
		}
		// 0101001010
		
	}
	return cnt;
}
unsigned int  maxx,t;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	for (int i=0;i<n;i++) cin >> ns[i];
	for (int i=0;i<n;i++) {
		ldts[i] = i;
		ls[i] = 1;
	}
	
	int d = 0;
	int r = n;
	int q = 0;
	while (d < 32) {
		int u = collect_1_num(d);
		d++;
		r = u;

	}
	
	sort(ldts,ldts+n,[](int a,int b){
		return ls[a] > ls[b];
	});
	int first=1;
	for (int j=0;j<m;j++) {
		int i = ldts[j];
		if (first == 1) {
			maxx = ns[i];
			first = 0;
		} else {
			maxx &= ns[i];
		}
	}
	
	cout << maxx << "\n";
	return 0;
} 
