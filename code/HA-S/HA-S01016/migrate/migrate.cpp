#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[10001],m,q[100001],b=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		b++;
		if(d%2==1){
			q[t]=0;
		}
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				if(x[i]+d<x[j])x[j]=0;
			}
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				m=x[i]-x[j];
				if(m>x[1]){
					if(m%d==1){
						q[b]++;
					}
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<q[i]<<endl;
	}
	return 0;
}
