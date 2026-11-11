#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, aa, cnt;
	cin >> n >> m;
	cnt=m;
	vector<int>cs(m+1);
	vector<int>mm(m+1);
	vector<int>mmm(m+1);
	for (int i=0;i<n;i++){
		cin >> aa;
		if (mm[aa]){
			for (int i=mm[aa];i>cnt;i--){
				cs[i]=0;
			}
			cnt=mm[aa];
		}
		cs[cnt]=aa;
		mm[aa]=cnt;
		cnt--;
	}
	for (int i=m;i>cnt;i--){
		cout << m[i] <<' ';
	}
	return 0;
}
