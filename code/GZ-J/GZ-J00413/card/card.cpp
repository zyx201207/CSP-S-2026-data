//GZ-J00413ºØÖªÓîº­
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[50005] = {0},d[50005] ={0},c[50005] = {0};
	for(int i = 0;i < n;i++){
		cin >> c[i];
	}
for(int i = 1;i <= n;i++){
		int cnt = 0;
		for(int j = 0; j <= cnt;j++){
			a[j] = 0;
		}
		for(int j = i - 1;j < n;j++){
			int temp  = -1;
			
			for(int k = 0 ; k < cnt;k++){
				if(a[k] == c[j]){
					
					temp = k;
					break;
				}
			}
			if(temp != -1){
				for(int k = temp + 1;k <= cnt;k++){
					a[k] = 0;
				}
				cnt = temp + 1;
			}else{
				a[cnt] = c[j];
				cnt++;
			}
		}
		for(int j = 0;j < cnt;j++){
			//cout << " a[j]: "<< a[j] <<endl;
			d[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << d[i] << " ";
	}
	return 0;
}
