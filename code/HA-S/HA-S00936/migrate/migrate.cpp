#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000010],g[2000010],ji,s;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>T;
while(T--){
	cin>>n>>d;
	ji=0;
	s=0;
	memset(a,0,sizeof(a));
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1)g[i]=a[i]-a[i-1];
		if(i>2){
			if(g[i]==g[i-1])ji++;
		}
	}
	if(ji==n-2){
		if(d>=g[2]*2){
			s=d/g[2];
			if(n-s*2+1<0){
				cout<<0;
				continue;
			}
			cout<<n-s*2+1;
		}
		else cout<<0;
		continue;
	}
}
return 0;
}
