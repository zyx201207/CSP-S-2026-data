//6,7,13
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=2e5;
ll n,m,a[N],x,dfsans=-1;
int s[1048580];

void dfs(ll id,ll ch,ll sum){//第id个人选，从ch开始选，之前总和为sum 
	if(id>m){
		dfsans=max(dfsans,sum);
		return;
	}
	for(int i=ch;i<=n;i++){
		dfs(id+1,i+1,sum&a[id]);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[i]=x;
		s[x]++;
	} 
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
	}else if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(n>2000){
		ll ans=1048575;
		for(int i=1048575;i>=0;i--){
			if(s[i]!=0 && m>0){
				ans=ans&i;
				m-=s[i];
			}
			if(m<=0) break;
		}
		cout<<ans;
	}else{
		dfs(1,1,1048575);
		cout<<dfsans;
	}
	
	
	return 0;
}
