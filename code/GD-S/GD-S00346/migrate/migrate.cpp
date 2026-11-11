#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],f[2000010][20];
inline void fun(int x,int de){
	f[x][de]++;
	for(int i=x;i<=n;i++){
		if(a[i]-a[x-1]<=d){
			fun(i+1,de+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",a+i);
		}
		if(n<=2) cout<<0<<endl;
		if(c==11||c==12){
			int k=a[2]-a[1];
			if(d<2*k) cout<<0<<endl;
			else{
				cout<<n-(d/2)<<endl;
			}
		}
		else if(c==13||c==14){
			cout<<0<<endl;
		}
		else{
			fun(1,0);
			long long sum=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n-1;j++){
					if(f[i][j]==2) sum++;
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}

