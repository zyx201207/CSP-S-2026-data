#include<bits/stdc++.h>
using namespace std;
int a[20001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int maxn = -1;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			if(a[i] & a[j] > maxn){
				maxn = a[i] & a[j];
			}
		}
	}
	cout << maxn;
	return 0;
}
