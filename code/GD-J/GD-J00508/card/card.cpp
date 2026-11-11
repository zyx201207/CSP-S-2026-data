#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5010],b[3010],t[3010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool ok = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i-1] > a[i])ok = 0;
	}
	for(int i = 1;i <= n;i++){
		int ba = 0,aa = i;
		while(aa <= n){
			if(ok == 1){
				if(b[ba] != a[aa]){
					b[++ba] = a[aa];
				}	
			}
			else{
				bool op = 1;
				for(int j = 1;j <= ba;j++){
					if(b[j] == a[aa]){
						ba = j;
						op = 0;
					}
				}
				if(op == 1){
					b[++ba] = a[aa];
				}
			}
			aa++;
		}
		for(int j = 1;j <= ba;j++){
			t[b[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << t[i] << " ";
	}
	return 0;
}
