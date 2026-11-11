#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long n,m,ans;
struct awa {
	long long val,cnt,x;
	string b;
} a[maxn];
bool cmp(awa a,awa b) {
	if(a.cnt!=b.cnt)return a.cnt>b.cnt;
	else return a.val>b.val;
}
void dfs(int cur,int cnt,long long x) {
	if(cnt==m) {
		ans=max(ans,x);
		return;
	}
	if(cur>n)return;
	for(int i=cur+1;i<=n;i++){
		dfs(i,cnt+1,x&a[i].val);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i].val;
	ans=0;
	if(m==n) {
		for(int i=1; i<=n; i++)ans&=a[i].val;
		cout<<ans<<"\n";
	} else if(m==1) {
		for(int i=1; i<=n; i++)ans=max(ans,a[i].val);
		cout<<ans<<"\n";

	} else if (m==2) {
		ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				ans=max(ans,a[i].val&a[j].val);
			}
		}
		cout<<ans<<"\n";
	} else {
		for(int i=1; i<=n; i++) {
			dfs(i,1,a[i].val);
		}
		for(int i=1; i<=n; i++) {
			int x=a[i].val;
			while(x>0) {
				if(x%2==1)a[i].cnt++,a[i].b+='1';
				else a[i].b+='0';
				x/=2;
			}
			reverse(a[i].b.begin(),a[i].b.end());
		}
		cout<<ans<<"\n";
	}
	return 0;
}

