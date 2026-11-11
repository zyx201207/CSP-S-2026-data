#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int max=0;
	if(m==1) {
		for(int i=1;i<=n;i++){
			if(a[i]>max) max=a[i];
		}
		cout << max;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=a[i] and a[j];
				if(x>max) max=x;
			}
		}
		cout << max;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=(a[i-1] and a[i]);
		}
		cout << a[n];
		return 0;
	}
	return 0;
}
