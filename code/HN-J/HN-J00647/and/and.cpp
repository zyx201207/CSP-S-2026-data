#include<bits/stdc++.h>
using namespace std;
const int N=2000+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		mx=max(mx,a[i]);
	}
	cout<<mx;
	return 0;
}
