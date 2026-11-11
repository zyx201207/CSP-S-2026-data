#include<bits/stdc++.h>
using namespace std;
int n,d;
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d",&n,&d);
		int isA=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])isA=0;
		}
		if(isA){
			long long k=x[2]-x[1];
			if(d<2*k)cout<<0<<'\n';
			else cout<<max(n-2*d/k+1,(long long)0)<<'\n';
		}else{
			cout<<"0"<<endl<<"1"<<'\n';
		}
	}
	return 0;
}
