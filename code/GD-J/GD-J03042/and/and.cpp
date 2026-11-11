#include <bits/stdc++.h>
using namespace std;
#define LL long long

int a[200005];
int m, n;
LL ans=-1;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}

	if(m==1){
		LL maxn=-1;
		for(int i=1; i<=n; i++){
			if(a[i]>maxn) maxn=a[i];
		}
		cout << maxn;
		return 0;
	}

	if(m==n){
		LL maxn=a[1];
		for(int i=2; i<=n; i++){
			maxn=maxn&a[i];
		}
		cout << maxn;
		return 0;
	}

	if(m==2){
		LL maxn=-1;
		for(int i=1; i<=n-1; i++){
			for(int j=i+1; j<=n; j++){
				int num=a[i]&a[j];
				if(num > maxn) maxn=num;
			}
		}
		cout << maxn;
		return 0;
	}

	if(m==n-1){
		LL maxn=-1;
		for(int i=1; i<=n; i++){
			int num;
			if(i==1) num=a[i+1];
			else num=a[i];
			for(int j=1; j<=n; j++){
				if(j==i) continue;
				num=num&a[j];
			}
			if(num>maxn) maxn=num;
		}
		cout << maxn;
		return 0;
	}
	return 0;
}
