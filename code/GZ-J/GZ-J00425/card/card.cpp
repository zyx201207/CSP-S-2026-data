//GZ-J00425 王武涛 兴义市弘毅中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAX=3e5+10,M=5e5+10;
ll n,m,i,j,l,ans[MAX],h[MAX],jump[MAX],cards[M];

void Pop(ll l,ll r){
	while(l<r){
		h[cards[l]]=-1;
		l++;
	}
	return;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	memset(h,-1,sizeof(h));
	for(i=1;i<=n;i++){
		ll card;
		scanf("%lld",&card);
		cards[i]=card;
		if(h[card]!=-1){
			jump[i]=h[card];
			Pop(h[card],i);
		}
		h[card]=i;
	}
	l=-1;
	for(i=n;i>=1;i--){
		if(i<l)l=-1;
		if(l==-1)ans[cards[i]]+=i;
		else{
			ans[cards[i]]+=i-l;
		}
		if(jump[i]!=0)l=jump[i];
	} 
	for(i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	printf("\n");
	return 0;
}

