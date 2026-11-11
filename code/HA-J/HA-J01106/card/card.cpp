#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005],b[100005],hhhh = 0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int jjjj = 1;jjjj<n;jjjj++){
		for(int i = 1;i < jjjj;i++){
		a[i] = n + 1;
	}
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == k){
				cnt++;	
			}
		}
		int cnf = 0,kkk = 0;
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
	for(int i = 1;i <= n-kkk+1;i++){
		if(b[i] == jjjj){
			hhhh++; 
		}
	} 
}
	cout << hhhh;
	return 0;
}
