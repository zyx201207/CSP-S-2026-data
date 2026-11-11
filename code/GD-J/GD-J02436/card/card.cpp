#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[555555],n,m,b[333333],mn[555555],z;
int find(int x){
	for(int i=1;i<z;i++){
		if(mn[i]==x){
			return i;
		}
	}
	return 0;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	z=1;
	for(int i=1;i<=n;i++){
		z=1;
		for(int j=i;j<=n;j++){
			if(find(a[j])){
				z=find(a[j]);
			}else{
				mn[z]=a[j];
			}
			z++;
		}
		for(int ii=1;ii<z;ii++){
			b[mn[ii]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
