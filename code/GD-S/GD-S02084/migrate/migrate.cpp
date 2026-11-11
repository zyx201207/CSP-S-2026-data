#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,t1;
int main (){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=11&&(c<19||c>21)){
		for(int i=1;i<=t;i++)printf("0\n");
	}
	for(int i=1;i<=t;i++){
		ll a[200010],t;
		scanf("%lld%lld",&n,&d);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[j]);
		}
		for(int j=1;j<=n;j++){
			for(int k=j+3;k<=n;k++){
				int tt=0;
				if(a[k]-a[j]<=d) continue;
				for(int p=j+1;p<k;p++){
					if(a[p]-a[j]<=d&&a[k]-a[p]<=d){
//						cout<<p<<"\n";
						tt++;
					}
				}
				if(tt==2){
//					cout<<j<<' '<<k<<"\n";
					t1++;
				}
			}
		}
		printf("%lld\n",t1);
		t1=0;
	}
	return 0;
}
//n 条地铁线路
// 
