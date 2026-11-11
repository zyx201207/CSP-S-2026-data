#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;//!!!
ll a[N],sum=0,n,d,u=0;

void solve(){
	ll ans=0;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		if(i!=n&&a[i+1]-a[i]>d)continue;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d)continue;
			int index=i,cnt=0;
			bool flag=true;
			while(index!=j){
				int tmp=lower_bound(a+index,a+n+1,a[index]+d)-a;
				if(a[tmp]-a[index]>d)tmp--;
				if(tmp==index){
					flag=false;
					break;
				}
				index=tmp;
				cnt++;
				if(tmp>j)break;
			}
//			cout<<cnt<<"\n";
			if(!flag)continue;
			if(cnt==2&&j-i==3)ans++;
			sum=0;
			
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,b[105];
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
