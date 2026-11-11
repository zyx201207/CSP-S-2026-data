#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(a[i] == a[j] && i != j){
				i = j;
			}
			else{
				b[a[i]]++;
			}
		}
	}
	b[a[n]] = n;
	for(int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	return 0;
}
