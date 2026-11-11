#include<bits/stdc++.h>
#define int long long

using namespace std;
int maxans=0;
int n,m;
int a[200005];
int p[200005];
void gn(int c,int wz){
	for(int i=wz;i<=n;i++){
		if(c<=m){
			p[c]=i;
			gn(c+1,wz+1);
		}
	}
	if(c==m){
		int an=a[p[1]];
		for(int i=2;i<=m;i++){
			an&=a[p[i]];
		}
		maxans=max(maxans,an);
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	gn(0,1);
	cout<<maxans<<endl;
	return 0;
}
