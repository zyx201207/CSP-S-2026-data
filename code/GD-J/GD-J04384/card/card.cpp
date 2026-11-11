#include<bits/stdc++.h>
using namespace std;
int a[50001];
int ton[30001];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int l = 1,r= l+1;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i =1;i <= n;i++){
		if (a[l]!= a[r]){
			r++;
		}else if(a[l]==a[r]){
			l = r;
			r++;
		}
		if(r == n){
			for(int j = l;j <= n;j++){
				ton[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ton[i] << " ";
	} 
	return 0;
} 
/*
4 3
1 2 1 3
*/
