#include<bits/stdc++.h> 
using namespace std;
const int N = 2e5 + 5;
int n,m,res,maxind = -1,prev_vecind,a[N],twoind[N],two[N][35];
vector<int> vec[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		int tmp = a[i];
		while(tmp){
			int p = tmp % 2;
			tmp /= 2;
			twoind[i] ++;
			two[i][twoind[i]] = p;
		}
		maxind = max(maxind,twoind[i]);
	}
	prev_vecind = maxind + 1;
	for(int i = 1;i <= n;i ++) vec[maxind + 1].push_back(i);
	for(int j = maxind;j >= 1;j --){
		for(int i : vec[prev_vecind]){
			if(twoind[i] < j) continue;
			if(two[i][j]) vec[j].push_back(i); 
		}
	    if((int)vec[j].size() >= m){
	    	res += (1 << (j - 1));
	    	prev_vecind = j;
		}
	}
	cout << res;
	return 0;
}
