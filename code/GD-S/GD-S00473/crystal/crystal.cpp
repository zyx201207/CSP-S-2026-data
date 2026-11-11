#include<bits/stdc++.h>
#define int int_fast64_t
using namespace std;
int a[int(5e5+5)];
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		int ans=1;
		for(int i=n;i>1;i--){
			int _m=m,cnt=0;
			for(int j=i-1;j;j--){
				if(a[i]-a[j]<=_m){
					_m-=(a[i]-a[j]);
					cnt++;
				}else break;
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
	}else{
		priority_queue<pair<int,int> > q;
		int sum=0,cnt=1,ans=1,id=1;
		for(int i=2;i<=n;i++){
			q.push({a[i]-a[i-1],id});
			sum+=(a[i]-a[i-1])*(id);
			id++;
			cnt++;
			while(q.size()&&sum>m){
				sum-=q.top().first*(q.top().second);
				q.pop();
				cnt--;
				id--;
			}
			if((q.empty()&&sum>m)||id<=0)break;
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	return 0;
}
//暴力+错误的正解结合体
