#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
int idx,t,n;
ll d,x[N],cnt[N],f[N],c[N],ans;
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		cnt[i]=f[i]=c[i]=0;
	}
	ans=0;
	for(int l=1;l<=n;l++){
		deque<int> dq;
		for(int i=0;i<=n;i++) f[i]=cnt[i]=c[i]=0;
		f[l]=0;
		cnt[l]=1;
		for(int r=l+1;r<=n;r++){
			while(!dq.empty()&&f[r-1]<f[dq.back()]){
				c[f[dq.back()]]-=cnt[dq.back()];
				dq.pop_back();
			}
			dq.push_back(r-1);
			c[f[r-1]]+=cnt[r-1];
			while(!dq.empty()&&x[r]-x[dq.front()]>d){
				c[f[dq.front()]]-=cnt[dq.front()];
				dq.pop_front();
			}
			int minid=dq.front();
			if(f[r]==f[minid]+1) cnt[r]+=c[f[minid]];
			else{
				f[r]=f[minid]+1;
				cnt[r]=c[f[minid]];
			}
		//	cout<<l<<" "<<r<<":"<<f[r]<<" "<<cnt[r]<<'\n';
			if(cnt[r]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>idx>>t;
	while(t--) work();
	return 0;
}
