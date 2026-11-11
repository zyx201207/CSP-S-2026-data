#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[500001],t[300001],t1[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++) t1[j]=0;
		stack<ll>q;
		for(ll j=i;j<=n;j++){
			if(t1[a[j]]==0) q.push(a[j]),t1[a[j]]=1;
			else while(q.top()!=a[j]){
				t1[q.top()]=0;
				q.pop();
			}
		}
		while(q.size()){
			t[q.top()]++;
			q.pop();
		}
	}
	for(ll i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}

