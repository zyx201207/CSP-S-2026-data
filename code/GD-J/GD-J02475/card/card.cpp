#include <bits/stdc++.h>
using namespace std;
struct T{
	int num;
	int tai=1;
}a[100005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, cnt[10005];
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i].num;
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(a[j].tai!=0){
				int flag=0; 
				for(int k=i; k<j; k++){
					if (flag==1)a[k].tai = 0;
					else if(a[k].num==a[j].num){
						flag=1;
						a[k].tai = 0;
					}
				}
			}
		}
		for(int i=1; i<=n; i++){
			a[i].tai = 1;
			cnt[a[i].num]++;
		}
	}
	for(int i=1; i<=m; i++){
		cout << cnt[i] << ' ';
	}
	return 0;
} 
