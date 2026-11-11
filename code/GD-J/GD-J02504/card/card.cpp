#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, id, c;
int a[N], b[N], num[N];
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 1;i <= n;i++){
		id = i;
		for(int j = i;j <= n;j++){
			int v = id;
			for(int z = i;z < v;z++){
				c = 0;
				if(b[z] == a[j]){
					c++;
					id = z;
					break;
				}
			}
			if(c == 0)b[id] = a[j];
			id++;
		}
		for(int j = i;j <= id - 1;j++)num[b[j]]++;
	}
	for(int i = 1;i <= m;i++)cout << num[i] <<" ";
}

