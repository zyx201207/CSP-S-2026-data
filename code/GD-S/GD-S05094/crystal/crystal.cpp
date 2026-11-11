#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int l[n] = {};
	for(int i = 0;i < n;i++){
		cin >> l[i];
	}
	sort(l,l+n);
	int Max = 2;
	for(int i = n-1;i > 0;i--){
		int khc = 1;
		long long czcs = 0;
		for(int j = i;j >= 0;j--){
			czcs += l[i]-l[j];
			if(czcs >= m){
				if(Max <= khc){
					Max = khc;
				}
				break;
			}
			khc++;
		}
	}
	cout << Max;
	return 0;
}
