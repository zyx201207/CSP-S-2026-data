#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e6+5;
int C,T,n;
ll d,x[N],ans = 0ll;
int q[N],front = 1,rear = 0;
ll dp[N],cnt[N],c = 0ll;
void solve1(){
	for(int i=1;i<=n;++i){
		front = 1; rear = 0;
		q[++rear] = i; dp[i] = 0ll; cnt[i] = 1ll; c = 1ll;
		for(int j=i+1;j<=n;++j){
			while(front<=rear && x[j]-x[q[front]] > d)c-=cnt[q[front]],++front;
			if(c <= 0ll && front<=rear){
				c = cnt[q[front]];
				for(int k=front+1;k<=rear;++k){
					if(dp[q[k]] == dp[q[front]])c += cnt[q[k]];
					else break;
				}
			}else if(c <= 0ll)c = 0ll;
			//for(int k=front;k<=rear;++k)cout<<q[k]<<" ";
			//cout<<endl<<c<<endl;
			cnt[j] = c, dp[j] = dp[q[front]]+1;
			if(cnt[j] == 2)++ans;
			//cout<<i<<" "<<j<<" "<<cnt[j]<<" "<<dp[j]<<endl;
			while(front<=rear && dp[q[rear]] > dp[j]){
				if(dp[q[rear]] == dp[q[front]])c -= cnt[q[rear]];
				--rear;
			}
			if(front > rear)c = cnt[j];
			else if(dp[q[front]] == dp[j])c += cnt[j];
			q[++rear] = j;
		}
	}
	printf("%lld\n",ans);
}
bool f1 = 1;
void solve2(){
	if(n <= 2){
		printf("0\n");
		return;
	}
	d = d/(x[2]-x[1]);
	if(d > 2){
		printf("0\n");
		return;
	}
	for(int i=1;i<=n;++i){
		if((ll)i+d+d-1 > (ll)n)break;
		//ans += min((ll)i+d+d-1,(ll)n)-((ll)i+d+1)+1;
		++ans;
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d); ans = 0ll;
		for(int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
			if(i > 2)f1 = (f1 && ((x[i]-x[i-1])==(x[i-1]-x[i-2])));
		}
		if(n <= 5000)solve1();
		else printf("0\n");
		//else if(f1)solve2();
	}
	return 0;
}
