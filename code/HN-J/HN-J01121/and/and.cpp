#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p[35];
int a[8000010][2],cnt,b[8000010];
void add(int x){
	int y=0,cc;
	for(int i=30;i>=0;i--){
		cc=(x>>i)&1;
		if(!a[y][cc]){
			a[y][cc]=++cnt;
		}
		y=a[y][cc];
		b[y]++;
	}
}
void ask(){
	int y=0,z,ans=0;
	for(int i=30;i>=0;i--){
		z=a[y][1];
		if(z&&b[z]>=m){
			ans+=p[i];
			y=z;
		}
		else y=a[y][0];
	}
	cout<<ans;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	p[0]=1;
	for(int i=1;i<=30;i++) p[i]=p[i-1]*2;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int z=-1;
		for(int j=0;j<=30;j++){
			int y=x&(p[j]-1);
			if(y==z) continue;
			z=y;
			add(y);
			if(x==y) break;
		}
	}
	ask();
	return 0;
}
