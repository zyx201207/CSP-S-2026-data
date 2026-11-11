#include<bits/stdc++.h>
using namespace std;
int a[100001], b[100001];
int main(){
	freopen("card.in","r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i< n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(a[i] == a[j]){
				for(int k = j+1;k < n;k++)b[a[k]]++;
			}else{
				for(int k = i+1; k <= j; k++) b[a[k]]++;
			}
		}
	}//初始化 用对列最优 
	for(int i = 0; i < n;i++){
		if(b[i]!=0) cout << b[i] << " ";
	}
	return 0;
}
