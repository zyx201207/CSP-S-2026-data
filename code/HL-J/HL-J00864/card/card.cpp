#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5*1e5+5;
int a[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i=1;i<=m;i++){
		cnt = 0;
		for(int j=1;j<=n;j++){
			if(a[j]==i) cnt++;
			for(int p=1;p<=j-1;p++){
				if(a[p]==a[j]){
					cnt+=j-p-1;
					for(int q=p;q<=j-1;q++){
						a[q]==0;
					}
				}
			}
		}
		cout << cnt << " ";
	}
	return 0;
}



