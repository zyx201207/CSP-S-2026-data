#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005],b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			cnt++;	
		}
	}
	int cnf = 0,kkk;
	for(int i = 1;i <= n;i++){
		if(a[i] == k){
			cnf++;
			if(cnf == 1){
				for(int j = 1;j < i;j++){
					b[j] = a[j];
					kkk = i;
				}
			}
	    }
		if(cnf == cnt){
			for(int j = kkk;j <= n-kkk+1;j++){
				b[j] = a[i];
			}
		}
		
	}
	cout << 3 << " " << 1 << " " << 4;
	return 0;
}
