#include <iostream>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,anx = 0;
	cin >> n >> m;
	int a[n],b[m] = {0};
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < m;i++) b[i] = i;
	while(b[0] < n){
		anx = a[b[0]];
		for(int i = 0;i < m;i++) anx &= a[b[i]];
		b[m - 1]++;
		for(int si = 0,i = m - 1;i > 0;i++){si = b[i] % n; b[i] %= n; b[i - 1] = si;}
		bool isr = false;
		for(int i = 0;i < m;i++) for(int j = 0;j < m;j++) if(a[i] == a[j]){isr = true;}
		if(isr){
			b[m - 1]++;
			for(int si = 0,i = m - 1;i > 0;i++){si = b[i] % n; b[i] %= n; b[i - 1] = si;}
			continue;
		}
		if(b[0] = n) break;
	}
	cout << anx << endl;
	return 0;
}
