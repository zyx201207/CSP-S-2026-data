#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt = 0;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a,a + n);
	long long cnt2 = 1;
	long long max = 0;
	for(int i = 1;i < n;i++){
		int miner = i - 1,maxer = i + 1;
		int ccc = m;
		while(ccc--){
			if(a[i] - a[miner] > a[maxer] - a[i]){
				a[miner]++;
				if(a[miner] == a[i]) miner--;
				continue;
			}else{
				a[maxer]++;
				if(a[maxer] == a[i]) maxer++;
				continue;
			}
		}
		for(int j = 0;j < n;j++){
			if(a[j] == a[j - 1]){
				cnt2++;
			}
		}
		if(max < cnt2){
			max = cnt2;
		}
	}
	cout << max + 2;
	return 0;
}
