#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
queue<int>q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int res=0;
	int nd=0;
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		nd+=(a[i]-a[i-1])*q.size();
		q.push(a[i]);
		if(nd>m){
			while(nd>m&&q.size()){
				nd-=a[i]-q.front();
				q.pop();
			}
		}
		res=max(res,(long long)(q.size()));
	}
	cout<<res;
	return 0;
}

