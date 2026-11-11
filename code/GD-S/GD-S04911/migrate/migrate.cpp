#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000010],fa[4000020],fi[4000020],to[4000020],k=0,s=0;
bool f;
void link(long long a,long long b){
	fa[k]=a;
	fi[a]=++k;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin<<c<<t;
	while(t--){
		cin<<n<<d;
		for(long long i=0;i<n;i++){
			cin<<x[i];
		}
	}
	return 0;
}
