#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e6+1;
stack<ll>s;
ll n,m,a[N],t[N],mx;
map<ll,int>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=n;i++){
		mp.clear();
		while(s.size()){
			s.pop();
		}
		for(int j=i;j<=n;j++){
			mp[a[j]]++;
			if(mp[a[j]]>1){
				mp[a[j]]=1;
				while(s.top()!=a[j]){
					if(s.top()==a[j])break;
					s.pop();
				}
			}else{
				s.push(a[j]);
			}
		}
		while(s.size()){
			t[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<t[i]<<" ";
	return 0;
}
