#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+5;
int n,m;
ll a[N],ans;
set<ll> se;
void opt(int f,int s,ll sum){
	if(s==m){
		se.insert(sum);
		return;
	}
	if(f==n+1) return;
	opt(f+1,s+1,sum?sum&a[f]:a[f]);
	opt(f+1,s,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>30){
		cout<<a[n-m];
	}
	opt(1,0,0);
	auto it=se.end();
	it--;
	cout<<*it;
	return 0;
}

