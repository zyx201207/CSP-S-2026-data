#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[5000005];
ll ans[5000005];
stack<ll>st;
map<ll,ll>mp,f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ga=1;
	while(ga<=n){
		mp.clear();
		for(int i=ga;i<=n;i++){
			if(!mp[a[i]]){
				st.push(a[i]);
				mp[a[i]]=1;
			} 
			else{
				while(!st.empty()){
					mp[st.top()]=0;
					if(st.top()==a[i]){
						mp[st.top()]=0;
						st.pop();
						break;
					}
				    st.pop();
				}st.push(a[i]);mp[a[i]]=1;
			}
		}
		while(!st.empty()){
			ans[st.top()]+=1;
			st.pop();
		}
		ga++;
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
