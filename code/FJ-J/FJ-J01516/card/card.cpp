#include<bits/stdc++.h>
using namespace std;
int n,m,c[300005];
bool f[300005];
int a[500005];
void zx(int k){
	memset(f,1,sizeof(f));
	for(int i=k;i<=n;i++){
		if(f[a[i]]){
			c[a[i]]++;
			f[a[i]]=false;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		zx(i);
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
