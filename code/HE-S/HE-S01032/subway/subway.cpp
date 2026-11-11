#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll zhan; ll t;
};
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ll c,n,m,d,p;
	node a1[505]={},a2[505]={},a3[505]={};
	ll walk[150000]={};
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&p);
	for(int i=0;i<m;i++)scanf("%lld",&walk[i]);
	ll k;
	for(int i=0;i<n;i++){
		scanf("%lld",k);
		if(i==0)for(int i=0;i<k;i++)scanf("%lld %lld",&a1[i].zhan,&a1[i].t);
		if(i==1)for(int i=0;i<k;i++)scanf("%lld %lld",&a2[i].zhan,&a2[i].t);
		if(i==2)for(int i=0;i<k;i++)scanf("%lld %lld",&a3[i].zhan,&a3[i].t);
	}
	ll st,en;
	ll ans=0;
	for(int i=0;i<p;i++){
		scanf("%lld %lld",&st,&en);
		ans+=walk[0];
		ans+=a1[0].t;ans+=a1[1].t;
		ans+=walk[1];
		printf("%lld\n",ans);
	}
	return 0;
}
