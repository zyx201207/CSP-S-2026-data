#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans=0;
queue<ll>q;
bool compare(int n,int m){
	return n<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,compare);
	for(int i=2;i<=n;i++){
		q.push(a[i]-a[i-1]);
	}
	ll temp;
	while(temp<=m){
		temp=q.front();
		q.pop();
		m-=temp;
		ans++;
	}
	cout<<ans;
	return 0;
}
