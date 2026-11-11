#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005];
ll t[300005],ans[300005];
stack<ll> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(t[a[j]]>0){
				while(!q.empty()&&q.top()!=a[j]){
					t[q.top()]--;
					q.pop();
				}
			}else {
				q.push(a[j]);
				t[a[j]]++;
			}
		}
		for(ll j=1;j<=m;j++){
			if(t[j]>0)ans[j]++;
			t[j]=0;
		}
		while(!q.empty()){
			q.pop();
		}
	}
	
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
		
	return 0;
} 
