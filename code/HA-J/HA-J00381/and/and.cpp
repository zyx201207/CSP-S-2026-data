#include<bits/stdc++.h>
using namespace std;
int a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx=-9999,s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=m;i--){
		s=a[i];
		for(int j=1;j<m;j++){
			s=s&a[i-j];
		}
		maxx=max(maxx,s);
	}
	cout<<maxx;
	return 0;
} 
