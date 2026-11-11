#include<bits/stdc++.h>
#define ll long long
#define plc pair<ll,char>
#define fi first
#define se second
using namespace std;
ll n,ans,maxn;
plc a[200005];
queue<plc>L;
stack<plc>R;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].fi>>a[i].se;
		maxn+=a[i].fi;
	}
	bool flag=0;
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i].fi;
		if(sum>maxn/2&&!flag){
			if(maxn%2==1){
				L.push({maxn/2-(sum-a[i].fi),a[i].se});
				R.push({(sum-maxn/2)-1,a[i].se});
			}
			else{
				L.push({maxn/2-(sum-a[i].fi),a[i].se});
				R.push({sum-maxn/2,a[i].se});
			}
			flag=1;
		}
		else if(!flag)L.push(a[i]);
		else R.push(a[i]);
	}
	while(!L.empty()&&!R.empty()){
		if(L.front().fi<R.top().fi){
			if(L.front().se!=R.top().se)ans+=L.front().fi;
			R.top().fi-=L.front().fi;
			L.pop();
		}
		else{
			if(L.front().se!=R.top().se)ans+=R.top().fi;
			L.front().fi-=R.top().fi;
			R.pop();
		}
	}
	cout<<ans;
	return 0;
}
//Wuhan meiga academy new bee!
