#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdout);
	freopen("card.out","w",stdin);
	vector<int>a[0];
	int i = 1;
	int m,n;
	int count = 0;
	cin >> n >> m;
	const int k = n;
	int b[k];
	for (int j = 0;j < n;j++){
		cin >> b[j];
	}
	for (int l = i-1;l < n;l++){
		for(int j = 0;j < a.length;j++){
			if (b[l] == a[j]){
				for(int p = j;p < length(a);p++){
					a.remove(p);
				}
			}
		}
		a.push(b[l]);
	}
	return 0;
}
