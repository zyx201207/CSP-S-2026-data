#include<bits/stdc++.h> 
using namespace std;
int n,m,a[200005],x,b[35],q,c[200005][35];
int o(int y){
	if(b[y]==m){
		b[y-1]=0;
		for(int i=1;i<=n;i++){
			if(c[i][y]==1)
			b[y-1]+=c[i][y-1];
			if(c[i][y]==1)
			if(x==0)
			x=a[i];
			else{
			x=a[i]&&x;
			return 0;
			}
		}
		cout<<x;
	
	}
	else
	o(y-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	x=a[1];
	if(n==m){
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(m==1){
		for(int i=2;i<=n;i++){
			x=max(x,a[i]);
		}
		cout<<x;
	}
	x=0;
		for(int i=1;i<=n;i++){
			int j=0;
			while(a[i]){
				b[j]+=a[i]%2;
				c[i][j]+=a[i]%2;
				a[i]/=2;
			}
		}
		for(int i=32;i<=1;i--){
			if(b[i]!=0&&q==0){
				q=i;
			}
		}
		o(q);
	return 0;
}
