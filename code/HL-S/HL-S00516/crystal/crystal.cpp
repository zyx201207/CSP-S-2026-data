#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500005],b[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++){
		a[1]++;
		sort(a+1,a+1+n);
	}
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			b[abs(a[i])]++;
		}else{
			c[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]>ans){
			ans=b[i];
		}else if(c[i]>ans){
			ans=c[i];
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/