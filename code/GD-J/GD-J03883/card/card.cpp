#include<bits/stdc++.h>
using namespace std;
int a[100005], n, m, p, d[100005], mm[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}
	int c;
	for (int i = 1; i <= n; i++){
		p=0;
		for(int j = i; j <= n; j++){
			c = d[j];
			for (int t = 1; t <= p; t++){
				if(a[t]==c){
					p = t-1;
					break;
				}
			}
			a[++p] = c;
		}
		for (int t = 1; t <= p; t++){
			mm[a[t]]++;
		}
	}
	for (int i = 1; i <= m; i++){
		cout << mm[i]<<" ";
	}
}
