#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000001],v[200001],l,s;
void dfs(int x,int y){
	if(x==m){
		if(l<=y)
		l=y;
	return;
}

	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			int h=y,f=a[i];
			y=(h&f);
			x++;
			dfs(x,y);
			y=h;
			x--;
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		v[i]=1;
		dfs(1,a[i]);
		v[i]=0;
	}
	cout<<l;
	return 0;
}
