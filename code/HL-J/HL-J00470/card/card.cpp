#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MAXM = 3005;
int a[MAXN],b[MAXN];
int ans[MAXM];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if (n <= 500 && m <= 200){
		for (int i = 1;i <= n;i++){
			int top = 1;
			for (int j = 1;j <= 5005;j++){
				b[j] = 0;
			}
			for (int j = i;j <= n;j++){
				bool ok = false;
				for (int k = 1;k <= top;k++){
					if (b[k] == a[j]){
						top = k+1;
						ok = true;
						break;
					}
				}
				if (!ok){
					b[top] = a[j];
					top+=1;
				}
			}
			for (int j = 1;j < top;j++){
				ans[b[j]]++;
				//cout << b[j] << " ";
			} 
			//cout << "\n";
		}
		for (int i = 1;i <= m;i++){
			cout << ans[i] << " ";
		}
	}else if (m == 1){
		cout << n;
	}else{
		multiset<int> mt;
		for (int i = 1;i <= n;i++){
			mt.insert(a[i]);
		}
		for (int i = 1;i <= m;i++){
			cout << mt.count(i) << " ";
		}
	}
}
