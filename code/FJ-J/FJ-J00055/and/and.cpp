#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=-2147483648,maxn=-2147483648;
	cin >> n >> m;
	if(m==n){
		cin >> sum;
		for(int i=2; i<=n; i++){
			int x;
			cin >> x;
			sum &=x;
		}
		cout << sum;
	} 
	if(m==(n-1)){
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(j!=i)sum&=a[j];
			}
			maxn=max(maxn,sum);
			cout <<maxn << ' ';
		}
		cout << maxn;
	}
	if(m==1){
		for(int i=1; i<=n; i++){
			int x;
			cin >> x;
			maxn=max(maxn,x);
		}
		cout << maxn;
	}
	if(m==2){
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout << maxn;
	}
	return 0;
}

