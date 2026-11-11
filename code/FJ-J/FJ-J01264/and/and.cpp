#include <bits/stdc++.h>
using namespace std;
int a[100005],t[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i++){
		c+=n-1;
	}
	for(int i=1;i<=c;i++){
		for(int j=i+1;j<=n;j++){
			t[i]=a[i]&a[j];
		}
	}
	int p=0;
	for(int i=1;i<=c;i++){
		max(p,t[i]);
		if(t[i]>p){
			p=t[i];
		}
	}
	cout << p;
	return 0;
}
