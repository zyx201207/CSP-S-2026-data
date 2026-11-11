#include<bits/stdc++.h>
#define ll long long 
#define MAXN 500005
using namespace std;
ll a[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;ll d;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++)
			printf("%d\n",1);	
		}
	}
	return 0;
}
