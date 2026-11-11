//GZ-J00006 观山湖中学 吴俊辰 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	vector<ll>ans(m+1,0);
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		stack<ll>q;
		vector<ll>v(m+1,0);
		for(ll j=i;j<=n;j++){
			if(v[a[j]]==0){
			q.push(a[j]);v[a[j]]=1;
		}
			else{
				while(1){
					if(q.top()==a[j]){
						v[q.top()]=0;
						q.pop();
						break;
					}
					v[q.top()]=0;
					q.pop();
				}
				q.push(a[j]);
				v[a[j]]=1;
			}
		}
		for(ll l=1;l<=m;l++){
			if(v[l]==1)ans[l]++;
		}
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

