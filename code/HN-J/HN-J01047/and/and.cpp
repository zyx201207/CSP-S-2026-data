//单调队列?? 
//DP??
//线段树??
//TQT~ 
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll n,m,a[N],t[N],ans,cnt;
deque<ll>dq;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dq.push_back(1);
	cnt=1;
	t[cnt]=a[1];
	for(int i=1;i<=n;i++){
		while(!dq.empty()&&dq.front()<i-m){
			t[cnt]&=a[m-dq.front()+1];
			dq.pop_front();
		}
		ans=max(ans,t[cnt]);
		ll b=cnt;
		while(!dq.empty()&&t[--b]<=t[cnt]){
			dq.pop_back();
		}
		dq.push_back(i);
		t[++cnt]&=a[i];
	}
	cout<<ans;
	return 0;
}
//4 2
//3 15 12 12
