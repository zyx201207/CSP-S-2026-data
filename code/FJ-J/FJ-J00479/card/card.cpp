#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5,M = 3E5+10;
int a[N],lst[M],cnt[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 0;i <= n;i++){
		cin >> a[i];
		lst[a[i]] = i;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		lst[a[i]] = i;
	}
	for(int i = 1;i <= n;i++){
		int j = i;
		while(j <= n){
			j = lst[a[j]];
			cnt[a[j]]++;
		}
	}
	return 0;
}
