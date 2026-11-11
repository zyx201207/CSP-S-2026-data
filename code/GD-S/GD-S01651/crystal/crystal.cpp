#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,a[N],m,sum,len=1,zd;//sum:队列内除去当前元素的元素总和 
queue<int>q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		q.push(a[i]);
		while(q.size()>1&&a[i]*((long long)q.size()-1)-sum>m){//调整成合法状态 
			sum-=q.front();
			q.pop();
		}
		sum+=a[i];
		zd=max(zd,(long long)q.size());
	}
	cout<<zd;
	return 0;
}
