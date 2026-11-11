#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<long long> a(n+5);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(a[i] < a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	
	long long cnt = a[1];
	for(int i = 1;i < m;i++){
		cnt = cnt & a[i+1];
	}
	cout << cnt;
	return 0;
}
