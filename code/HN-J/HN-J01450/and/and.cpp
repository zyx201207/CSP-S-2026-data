#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000000];
int mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}for(int i = 0;i < n-1;i++){
		for(int j = i+1;j < n;j++){
			mx = max (mx,a[i]&a[j]);
		}
	}
	cout << mx;
}
