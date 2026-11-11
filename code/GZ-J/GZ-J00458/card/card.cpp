//GZ-J00458 邓可为 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],c[300010];
ll b[300010]={0};
queue<ll> Q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	for(ll j=1;j<=n;j++){
	while(!Q.empty()){
		Q.pop();
	}	
	
	for(int i=1;i<=n;i++)
		b[i] = 0;
	
	for(int i=j-1;i<=n;i++){
		if(b[a[i]] == 0){
			b[a[i]] = i;
			Q.push(a[i]);
		}
		else{
			ll y = i-1;
			while(!Q.empty()){
				if(y!=0){
					Q.push(Q.front());
					y--;
				}
				Q.pop();
			} 
			b[a[i]] = Q.size();
			Q.push(a[i]);
		}
	}
		while(!Q.empty()){
			c[Q.front()]++;
			Q.pop();
		}
	}
	
	for(int i=1;i<=m;i++)
		printf("%lld ",c[i]);
	return 0;
} 
