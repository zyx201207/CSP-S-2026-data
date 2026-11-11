//GZ-J00270,贵阳市第一实验中学，闵梦琪
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int m,n;
	cin >> n >> m;
	int cnt =0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s = a[i]&a[j];
			cnt = max(s,cnt);
		}
	}
	cout << cnt;
	return 0;
} 
