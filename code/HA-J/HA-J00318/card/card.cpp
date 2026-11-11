#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll num[10000005];
ll mun[10000005];
ll ans[10000005];
ll q[10000005];
void qing(ll c,ll b){
	for(int i=c;i<=b;i++){
		q[i]=0;
	}
}
void zhao(int a){
	memset(num,0,sizeof(num));
	memset(q,0,sizeof(q));
	
	for(int i=a;i<=n;i++){
		q[i]=mun[i];
		num[mun[i]]=i;
		if(num[mun[i]]!=0){
			qing(num[mun[i]],i-1);
			num[mun[i]]=0;
		}
	}
	for(int i=a;i<=n;i++){
		if(q[i]!=0){
			ans[q[i]]++;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>mun[i];
	}
	for(int i=1;i<=n;i++){
		zhao(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
