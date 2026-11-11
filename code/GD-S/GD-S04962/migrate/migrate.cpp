#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005;
ll c,t,n,d;
ll a[N];
ll sum[N];
bool temp;

void fly(ll u,ll v,ll num){
	if(v==u){
		sum[num]++;
		temp=1;
		return;
	}
	for(int i=u+1;i<=v;i++){
		if(a[i]-a[u]<=d){
			fly(i,v,num+1);
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;			
		memset(sum,0,sizeof(sum));
		for(int j=1;j<=n;j++) cin>>a[j];
		ll ans2=0;
		for(int j=1;j<=n;j++){
			for(int k=j+3;k<=n;k++) {
				ll num;
				memset(sum,0,sizeof(sum));
				temp=0;
				fly(j,k,0);
				if(temp!=0){
					ll ans3=0;
					ll num=0x3f3f3f;
					for(int i=1;i<=n;i++){
						if(sum[i]==0) continue;
						if(num>=i&&ans3<=sum[i]) {
							ans3=sum[i];
							num=i;
						}
					}
					if(ans3==2) ans2++;
				}
			}
		}
		cout<<ans2<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/


