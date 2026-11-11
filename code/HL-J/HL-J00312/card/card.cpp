#include <bits/stdc++.h>
using namespace std;
int mn[200010];
int find(int x,vector<int> v1,int k){
	for (int i = 0;i < k;i++){
		if (v1[i] == x){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n + 1];
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		vector<int> v(m);
		int t = 0;
		for (int j = i;j <= n;j++){
			if (find(a[j],v,t) == -1){
				v[t] = a[j];
				t++;
			}else{
				t = find(a[j],v,t) + 1;
			}
		}
		for (int j = 0;j < t;j++){
			mn[v[j]] ++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << mn[i] << " ";
	}
} 
