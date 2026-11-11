#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	queue<int> q;
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cost=0;
	int x;
	int ans=0;
	int len=0;
	for(int i=1;i<=n;i++){
		q.push(i);
		len++;
		cost+=(len-1)*(a[i]-a[i-1]);
		while(cost>m&&len){
			x=q.front();
			q.pop();
			len--;
			cost-=a[i]-a[x];
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
