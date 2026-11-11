#include<bits/stdc++.h>
using namespace std ;
long long a[2000010];
long long b[2000010];
long long c[2000010];
long long n,m;
void p(int x,int y){
	if (x != c[y]){
		return ;
	}
	if (y > n){
		return ;
	}
	b[y] ++;
	for(int i=1;i<=n-y;i++){
		p(x+1,y+i);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int d,t;
	cin>>d>>t;
	while (t--){
		cin>>n>>m;
		int y;
		for(int i=1;i<=n;i++){
			b[i] = 0;
	 		int x;
	 		cin>>x;
	 		if (i == 1){
	 			y = x;
			 }
	 		x-= y;
	 		if (x < 0) x*= -1;
	 		c[i] = x / m;
			if (x % m != 0) c[i] ++;
	 		a[i] = x - a[i-1];
		 }
		c[1] = 0;
		p(0,1);
		int num = 0;
		for(int i=1;i<=n;i++){
			if (b[i]==2){
				num++;
			}
		}
		cout<<num;
	}
	return 0;
}
