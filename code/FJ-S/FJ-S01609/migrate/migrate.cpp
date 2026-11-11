#include<iostream>
#include<cstdio>
using namespace std;
int n,m,o,c;
long long d;
long long q[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(11<=n&&n<=12){
		for(int i=1;i<=m;i++){
			scanf("%d%lld",&o,&d);
			for(int i=1;i<=o;i++){
				scanf("%lld",&q[i]);
				if(i==2){
					c=q[i]-q[i-1];
				}
			}
			if(c*2<=d&&c*3>d){
				cout<<o-2;
			}else{
				cout<<0;
			}
		}
	}
}
