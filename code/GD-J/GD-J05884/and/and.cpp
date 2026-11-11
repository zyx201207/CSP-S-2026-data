#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,ans=0,lz,l=0;
int a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	 lz=a[0];
	for(int i=1;i<n;i++){
		lz&=a[i];
	}
	if(n==m){
		cout<<lz;
	}
	sort(a,a+n);
	l=n-2;
	ans=a[n-1];
	--m;
	while(m--){
		ans&=a[l--];
	}
	cout<<ans;
	return 0;
} 
