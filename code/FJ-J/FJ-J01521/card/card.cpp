#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500010];
int desk[500010];
int b[500010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		//int e;
		for(int j = i - 1;j<n;j++){
			int e = 0;
			for(int k = 0;k<=j;k++){
				if(desk[k] == 0){
					desk[k] = a[j];
					e = k;
					break;
				}
			}
			bool flag = 0;
			for(int k = 0;k<e;k++){ 
				if(flag){
					desk[k] = 0;
				}
				if(desk[k] == a[j]){
					flag = 1;
				}
			}
			//==============================
			for(int k = 0;k<=e;k++){
				if(desk[k] == 0) break;
				//cout << desk[k] << ' ';
			}
			//cout << '\n';
		}

		//cout << '/'; 
		for(int j = 0;j<=n;j++){
			if(desk[j] == 0) break;
			b[desk[j]]++;
			//cout << desk[j] << ' ';
			desk[j] = 0;
		}
		//cout << '\n';
		for(int j = 0;j<=n;j++){
			if(desk[j] != 0) desk[j] = 0;
		}
	}
	for(int i = 1;i<=m;i++){
		cout << b[i] << ' ';
	}
	return 0;
}
