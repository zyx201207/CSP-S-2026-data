#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5;

int n,m;
int tot;
int now;
int ans=1;
int a[N+5];
int cnt[N+5];
queue<int> p;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cnt[1]=1;
	now=1;
	p.push(a[1]);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]) cnt[i]=cnt[i-1]+1;
		else{
			tot+=now*(a[i]-a[i-1]);
			while(!p.empty()&&tot>m){
				tot=tot-(a[i]-p.front());
				p.pop();
				now--;
			}
			cnt[i]=now+1;
		}
		now++;
		p.push(a[i]);
		ans=max(ans,cnt[i]);
	}
	cout<<ans;
	return 0;
} 
