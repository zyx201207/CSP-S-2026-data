#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],lz;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=m;j++){
			if(a[i]&a[j]>lz){
				lz=a[i]&a[j];
			}
		}
	}
	for(int i=1,j=n;i<=j;i++,j--){
		for(int z=1;z<=m;z++){
			if(a[i]&a[j]>lz){
				lz=a[i]&a[j];
			}
	}
}
int l[200005],cnt=0;
	while(lz){
	l[++cnt]=lz%10;
	lz/=10;
	}
	reverse(l+1,l+cnt+1);
	for(int i=1;i<=cnt;i++){
		cout<<l[i];
	}
	return 0;
}
