#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
int diff[N];
queue<int> d;
queue<int> d2;
int need=0;
int tot=0;
int ans=0;
int cnt=0;
int sum=0;
/*
5 5
1 2 4 8 9

*/
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=2;i<=n;i++){
		diff[++tot]=abs(a[i]-a[i-1]);
	}
	for(int i=1;i<=tot;i++){
		ans+=d.size()*diff[i]+diff[i];
		cnt+=diff[i];
		d.push(diff[i]);
		d2.push(diff[i]);
		while(ans>m&&!d.empty()){
			ans-=cnt;
			cnt-=d.front();
			d.pop();
			d2.pop();
		}
		int num=d.size()+1;
		sum=max(num,sum);
	}
	cout<<sum<<'\n';
	
}
