#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,T,n;
ll d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(i<=2) continue;
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				n=i-1;
				break;
			}
		} 
		ll res=a[2]-a[1];
		//cout<<n<<" "<<res<<" "<<d<<endl;
			int len=d/res;
			if(len<2||n-(len+len-1)<0){
				cout<<0<<endl;
			}
			else cout<<n-(len+len-1)<<endl;
		
	}
	return 0;
}
