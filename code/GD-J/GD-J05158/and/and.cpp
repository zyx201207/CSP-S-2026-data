#include<bits/stdc++.h>
using namespace std;
const int N=2e5+500;
bool b[N],c[N];
int rest;
int a[N][64];
int n,m;
bool check(int x){
	int re=rest;
	for(int i=1;i<=n;i++){
		c[i]=b[i];
		if(a[i][x]==0&&b[i]==true){
			re--;
			c[i]=false;
		}
	}
	if(re>=m){
		rest=re;
		for(int i=1;i<=n;i++){
			b[i]=c[i];
		}
		return true;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	rest=n;
	for(int i=1;i<=n;i++){
		b[i]=true;
		int x;
		scanf("%d",&x);
		int len=0;
		while(x){
			a[i][len++]=x&1;
			x>>=1;
		}
	}
	int ans=0;
	for(int i=31;i>=0;i--){
		if(check(i)){
			ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
} 
