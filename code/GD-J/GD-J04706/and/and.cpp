#include <bits/stdc++.h> 
using namespace std;
long long n,m,mx=0;
long long a[200010],b[105],b2[105],b3[105],l=1; 
bool h[200010];
int f(int x,int y){
	int u=0,u2=0,u3=0;
	while (x){
		b[++u]=x%2;
		x/=2;
	}
	while (y){
		b2[++u2]=y%2;
		y/=2;
	}
	for (int i=1;i<=max(u,u2);i++){
		if (b[i]==1&&b2[i]==1){
			b3[++u3]=1;
		}
		else{
			b3[++u3]=0;
		}
	}
	long long z=1,z2=0;
	for (int i=1;i<=u3;i++){
		z2+=b3[i]*z;
		z*=2;
	}
	for (int i=1;i<=35;i++){
		b[i]=b2[i]=b3[i]=0;
	}
	return z2;
}
void dfs(int p,long long x){
	//cout <<x<<endl;
	if (p==m){
		mx=max(mx,x);
		return;
	}
	for (int i=1;i<=n;i++){
		if (!h[i]){
			h[i]=true;
			//cout <<x<<" "<<a[i]<<endl;
			dfs(p+1,f(a[i],x));
			h[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	for (int i=1;i<=n;i++){
		h[i]=true;
		dfs(1,a[i]);
		h[i]=false;
	}
	cout <<mx;
	return 0;
}
