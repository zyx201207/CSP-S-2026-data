#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],ma,b[200001],k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","l",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;k=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		b[i]=i;
	}
	b[m+1]=n+1;
	while(k>0){
		int c=a[b[1]];
		cout<<b[1]<<" ";
		for(int i=2;i<=m;i++){
			c=c&a[b[i]];
			cout<<b[i]<<" ";
		}
		cout<<endl;
		ma=max(ma,c);
		if(b[k]+1==b[k+1]){
			k--;
			b[k]++;
		}
		else{
			b[k]++;
		}
	}
	cout<<ma;
	return 0;
}
