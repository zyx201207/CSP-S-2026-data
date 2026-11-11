#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,cnt,a[N],sum,ans;
queue<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=(a[i]-a[i-1])*cnt;
		while(!q.empty()&&sum>m){
			int tmp=q.front();
			sum-=a[i]-tmp;
			q.pop();
			cnt--;
		}
		q.push(a[i]);
		cnt++;
		ans=max(ans,cnt);
	}
	cout<<ans;
} //14:46
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
