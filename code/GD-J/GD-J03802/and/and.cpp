#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,m;
int a[N];
int mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	int l = a[0];
	if(m == 1){
		for(int i = 0;i < n;i++) mx = max(a[i],mx);
	}
	if(m == 2){
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(i != j){
					mx = max(a[i] & a[j], mx);
				}	
			}
		} 
	}
	if(m > 2 && m == n){
		for(int i = 1;i < n;i++){
			l = l & a[i];
		}
		mx = l;
	}
	cout << mx;
	return 0;
} 

