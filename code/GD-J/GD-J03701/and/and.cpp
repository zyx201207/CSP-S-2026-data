#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n],sum=0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(m == 2){
		for(int i = 1;i <=n;i++){
			for(int j = i+1;j <= n;j++){
				int pqo;
				pqo = a[i] & a[j];
				sum = max(sum,pqo);
			}
		}
	}else if(m == 3){
		for(int i = 1;i <=n;i++){
			for(int j = i+1;j <= n;j++){
				for(int k = j+1;k <= n;k++){
					int pqo;
					pqo = a[i] & a[j] & a[k];
					sum = max(sum,pqo);
				}
			}
		}
	}
	cout << sum;
	
	return 0;
}

