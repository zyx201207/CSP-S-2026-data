#include<bits/stdc++.h>
using namespace std;
long long y[2001][2001],s;
int ad(int a,int b,int c,int d){
	int z;
	if(a==b){
		if(c==2){
			return 1;
		}else{
			return 0;
		}
	}
	for(int i=1;i<=d;i++){
		if(y[a][b]==1){
			c++;
		}
		z=ad(a+i,b,c,d);
	}
	return z;
}
int main() {
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int x[2000001];
	for(int i=0;i<t;i++){
		s=0;
		int n,d;
		cin>>n>>d;
		for(int i1=1;i1<=n;i1++){
			for(int i2=1;i2<=n;i2++){
				y[i1][i2]=0;	
			}
		}
		for(int i1=1;i1<=n;i1++){
			cin>>x[i1];
		}
		for(int i2=1;i2<=n;i2++){
			for(int i3=i2+1;i3<=n;i3++){
				if(x[i3]-x[i2]<=d){
					y[i2][i3]=1;
				}
			}
		}
		for(int i1=1;i1<=n;i1++){
			for(int i2=i1+1;i2<=n;i2++){
				s+=ad(i1,i2,0,d);
			}
		}
		cout<<s;
	}
	return 0;
}
