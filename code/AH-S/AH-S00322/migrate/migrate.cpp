/*
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
#define debug(x) cerr<<"["<<#x<<"]: "<<x<<"\n";
using namespace std;
const int MOD=1e9+7;
ll INF=1e18;
const int N=2000005;
int n,d;
int a[N];
int pre[N],nxt[N];
bool chk(int s,int t){
	vector<int> vec1,vec2;
	int now=s;
	while(now<t){
		if(now!=s){
			vec1.push_back(now);
		}
		if(nxt[now]==now)return 0;
		now=nxt[now];
	}
	now=t;
	while(now>s){
		if(now!=t){
			vec2.push_back(now);
		}
		assert(pre[now]!=now);
		now=pre[now];
	}
	reverse(ALL(vec2));
	if(vec1==vec2)return 0;
	assert(vec1.size()==vec2.size());
	bool flg=0;
	for(int i=0;i<vec1.size();i++){
		if(vec1[i]!=vec2[i]){
			if(flg)return 0;
			if(vec1[i]!=vec2[i]+1){
				return 0;
			}
			flg=1;
		}
	}
	return 1;
}
int f[N],g[N];
void solve_(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<"0\n";
		return;
	}
	
	return;
	int now=1;
	for(int i=1;i<=n;i++){
		while(now<i&&a[i]-a[now]>d){
			now++;
		}
		assert(a[i]-a[now]<=d);
		pre[i]=now;
	}
	now=n;
	for(int i=n;i>=1;i--){
		while(now>i&&a[now]-a[i]>d){
			now--;
		}
		assert(a[now]-a[i]<=d);
		nxt[i]=now;
	}
	for(int i=1;i<=n;i++){
		f[i]=g[i]=0;
		debug(i);
		debug(pre[i]);
		debug(nxt[i]);
	}
	for(int i=1;i<=n;i++){
		if(pre[i]!=i){
			if(nxt[pre[i]]==i){
				f[i]=f[pre[i]];
			}
		}
		f[i]+=1;
		for(int j=pre[i]+1;j<i;j++){
			if(nxt[j]==i){
				f[i]++;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(nxt[i]!=i){
			if(pre[nxt[i]]==i){
				g[i]=g[nxt[i]];
			}
		}
		g[i]+=1;
		for(int j=i+1;j<nxt[i];j++){
			if(pre[j]==i){
				g[i]++;
			}
		}
	}
	debug(g[8]);
	debug(nxt[8]);
	debug(pre[9]);
	int ans=0;
	//1
	for(int i=1;i<n;i++){
		//i i+1
		int y=nxt[i+1];
		if(pre[y]!=i)continue;
		//s>x
		int cnt=0;
		for(int j=pre[i]+1;j<=i;j++){
			if(nxt[j]==i+1){
				cnt++;
			}
		}
		ans+=cnt*(g[y]);
		//debug(i);
		//debug(y);
		//debug(cnt*(g[y]+1));
	}
	//2
	for(int i=1;i<n;i++){
		//i i+1
		int x=pre[i];
		if(nxt[x]!=i+1)continue;
		//s>x
		int cnt=0;
		for(int j=i+1;j<nxt[i+1];j++){
			if(pre[j]==i){
				cnt++;
			}
		}
		//debug(i);
		//debug(cnt);
		//debug(f[x]);
		ans+=cnt*(f[x]);
	}
	//3 dou bu he fa
	for(int i=1;i<n;i++){
		//i i+1
		int cnt1=0,cnt2=0;
		for(int j=pre[i]+1;j<=i;j++){
			if(nxt[j]==i+1){
				cnt1++;
			}
		}
		for(int j=i+1;j<nxt[i+1];j++){
			if(pre[j]==i){
				cnt2++;
			}
		}
		
		ans+=cnt1*cnt2;
	}
	//4 dou he fa
	for(int i=1;i<n;i++){
		//i i+1
		int x=pre[i],y=nxt[i+1];
		if(!(nxt[x]==i+1&&pre[y]==i)){
			continue;
		}
		ans+=(f[x]-1)*(g[y]-1)+1;
		debug(i);
		debug(x);
		debug(y);
		debug((f[x]-1)*(g[y]-1));
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cid=0,multitest=1,testcase=1;
	if(multitest)cin>>cid>>testcase;
	while(testcase--){
		solve_();
	}
	return 0;
}
*/
#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int,int>
#define ALL(x) x.begin(),x.end()
#define debug(x) cerr<<"["<<#x<<"]: "<<x<<"\n";
using namespace std;
const int MOD=1e9+7;
ll INF=1e18;
const int N=2000005;
int n,d;
int a[N];
int pre[N],nxt[N];
bool chk(int s,int t){
	vector<int> vec1,vec2;
	int now=s;
	while(now<t){
		if(now!=s){
			vec1.push_back(now);
		}
		if(nxt[now]==now)return 0;
		now=nxt[now];
	}
	now=t;
	while(now>s){
		if(now!=t){
			vec2.push_back(now);
		}
		assert(pre[now]!=now);
		now=pre[now];
	}
	reverse(ALL(vec2));
	if(vec1==vec2)return 0;
	assert(vec1.size()==vec2.size());
	bool flg=0;
	for(int i=0;i<vec1.size();i++){
		if(vec1[i]!=vec2[i]){
			if(flg)return 0;
			if(vec1[i]!=vec2[i]+1){
				return 0;
			}
			flg=1;
		}
	}
	//if(1){
	//	cout<<"{";
	//	for(auto i:vec1){
	//		cerr<<i<<" ";
	//	}
	//	cerr<<"}\n";
	//	cout<<"{";
	//	for(auto i:vec2){
	//		cerr<<i<<" ";
	//	}
	//	cerr<<"}\n";
	//}
	return 1;
}
void solve_(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		cout<<"0\n";
		return;
	}
	int now=1;
	for(int i=1;i<=n;i++){
		while(now<i&&a[i]-a[now]>d){
			now++;
		}
		assert(a[i]-a[now]<=d);
		pre[i]=now;
	}
	now=n;
	for(int i=n;i>=1;i--){
		while(now>i&&a[now]-a[i]>d){
			now--;
		}
		assert(a[now]-a[i]<=d);
		nxt[i]=now;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(chk(i,j)){
				cerr<<i<<" "<<j<<"\n";
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cid=0,multitest=1,testcase=1;
	if(multitest)cin>>cid>>testcase;
	while(testcase--){
		solve_();
	}
	return 0;
}
