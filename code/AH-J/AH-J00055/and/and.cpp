#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e5+10;
int n,m;
ll a[N],dp[N],mx=INT_MIN,ans,vis[N],cnt1,cnt2,cnt3;
stack<int> st;
void dfs(ll dep,ll id){
	if(dep>m){
		ll ans1=st.top();
		stack<int> st1;
		while(!st.empty()){
			ans1=ans1&st.top();
			st1.push(st.top());
			st.pop();
		}
		while(!st1.empty()){
			st.push(st1.top());
			st1.pop();
		}
		ans=max(ans1,ans);
		return;
	}
	for(int i=id;i<=n;++i){
		if(vis[i]) continue;
		else{
			vis[i]=1;
			st.push(a[i]);
			if(dep==0) dfs(dep+1,i);
			else dfs(dep+1,i);
			st.pop();
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
		dp[i]=a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout << mx;
	}else if(m==n){
		for(int i=1;i<=n;++i){
			if(i==1){
				ans=a[i];
			}else{
				ans=ans&a[i];
			}
		}
		cout << ans;
	}else if(m==2){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j) continue;
				else{
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout << ans;
	}else if(n<=20){
		dfs(1,1);
		cout << ans;
	}else if(mx<4){
		for(int i=1;i<=n;++i){
			if(a[i]==3) cnt3++;
			else if(a[i]==2) cnt2++;
			else if(a[i]==1) cnt1++;
		}
		if(cnt3>=m){
			cout << 3;
		}else if(cnt3+cnt2>=m){
			cout << 2;
		}else{
			cout << 1;
		}
	}else{
		cout << mx;
	}
	return 0;
}
