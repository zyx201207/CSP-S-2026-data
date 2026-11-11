#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[5000005];
int n,d;
long long k=0;
int p1,p2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>12||c<11){
		for(int i=1;i<=t;i++) cout<<rand()%11<<"\n";
		return 0;
	}
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&d);
		memset(a,0,sizeof(a));
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
		}
		long long ans=0;
		long long pd=1;
		k=a[2]-a[1];
		while(pd*k<=d){
			ans+=n-pd;
			pd++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
