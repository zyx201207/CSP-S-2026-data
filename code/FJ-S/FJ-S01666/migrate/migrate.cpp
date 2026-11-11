#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+5;
ll c,T,n,d,x[N],dp[N],f[N],q[N],head,tail,minn,s,cnt[N],ans;
void solve(){
	cin >>n>>d;
	for(int i=1;i<=n;i++)cin >>x[i];
	ans=0;
	if(c==11||c==12){
		dp[1]=0;
		f[1]=1;
		minn=0;
		for(int j=1;j<=n;j++)cnt[j]=0;
		cnt[0]=1;
		head=tail=1;
		q[1]=1;
		for(int j=2;j<=n;j++){
			while(head<=tail&&x[j]-x[q[head]]>d){
				cnt[dp[q[head]]]-=f[q[head]];
				++head;
			}
			if(head>tail)break;
			dp[j]=dp[q[head]]+1;
			f[j]=cnt[dp[q[head]]];
			if(f[j]==2)ans+=n-j+1;
			while(head<=tail&&dp[j]<dp[q[tail]]){
				cnt[dp[q[tail]]]-=f[q[tail]];
				--tail;
			}
			q[++tail]=j;
			cnt[dp[j]]+=f[j];
		}
		cout <<ans<<"\n";
		return;
	}
	if(c==13||c==14){
		int rt=0;
		for(int i=1;i<=n;i++){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
				rt=i;
				break;
			}
		}
		int l=1,r=0;
		head=1;
		tail=0;
		for(int i=1;i<=rt;i++)q[++tail]=i;
		for(int i=rt+1;i<=n;i++){
			while(head<=tail&&x[i]-x[q[head]]>d)++head;
			q[++tail]=i;
			while(l<=r){
				if(tail-head<1)++l;
				else if(x[q[head+1]]-x[l]>d)++l;
				else break;
			}
			while(r<rt){
				if(tail-head<1)break;
				if(x[q[head+1]]-x[r+1]<=d&&(head-tail==1||x[q[head+2]]-x[r+1]>d))++r;
				else break;
			}
			ans+=r-l+1;
		}
		cout <<ans<<"\n";
		return;
	}
	for(int i=1;i<n;i++){
		dp[i]=0;
		f[i]=1;
		minn=0;
		for(int j=1;j<=n;j++)cnt[j]=0;
		cnt[0]=1;
		head=tail=1;
		q[1]=i;
		for(int j=i+1;j<=n;j++){
			while(head<=tail&&x[j]-x[q[head]]>d){
				cnt[dp[q[head]]]-=f[q[head]];
				++head;
			}
			if(head>tail)break;
			dp[j]=dp[q[head]]+1;
			f[j]=cnt[dp[q[head]]];
			if(f[j]==2)ans++;
			while(head<=tail&&dp[j]<dp[q[tail]]){
				cnt[dp[q[tail]]]-=f[q[tail]];
				--tail;
			}
			q[++tail]=j;
			cnt[dp[j]]+=f[j];
		}
	}
	cout <<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c>>T;
	while(T--)solve();
}
