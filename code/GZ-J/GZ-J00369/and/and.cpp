//GZ-J00369 Íõ×ÓÇ¬
#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int mx=INT_MIN;
int n,m,a[N],s;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	s=a[1];
	if(n==m){
		for(int i=1;i<=n;i++){
			if(i+1<=n){
				s=s&a[i]&a[i+1];
			}
		}
		cout << s;
	}
	else{
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout << mx;
	}
	return 0;
}
