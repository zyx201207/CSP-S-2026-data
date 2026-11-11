#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long cnt[105];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int maxn=30;
	long long ans=0;
	vector<long long> v;
	vector<long long> nxt;
	for(int i=1;i<=n;i++) v.push_back(a[i]);
	while(true){
		memset(cnt,0,sizeof cnt);
		int len=v.size();
		for(int i=0;i<len;i++){
			int id=1;
			int k=v[i];
			while(k){
				if(k%2==1){
					cnt[id]++;
				}
				k/=2;
				id++;
			}
		}
		int last=maxn;
		for(int i=maxn-1;i>=1;i--){
			if(cnt[i]>=m){
				maxn=i;
				break;
			}
		}
		if(maxn==last){
			cout<<ans<<'\n';
			return 0;
		}
		long long p=1;
		for(int i=1;i<=maxn-1;i++) p*=2;
		ans+=p;
		while(nxt.size()) nxt.pop_back();
		len=v.size();
		for(int i=0;i<len;i++) nxt.push_back(v[i]);
		while(v.size()) v.pop_back();
		for(int i=0;i<len;i++){
			int id=1;
			int k=nxt[i];
			while(k){
				if(k%2==1&&id==maxn){
					v.push_back(nxt[i]);
					break;
				}
				k/=2;
				id++;
			}
		}
	}
	return 0;
}
