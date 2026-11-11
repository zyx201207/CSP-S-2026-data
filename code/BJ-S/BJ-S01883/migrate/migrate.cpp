#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x":"<<(x)<<' '
#define dbe(x) cerr<<#x":"<<(x)<<'\n'
#define eb emplace_back
#define ep emplace
#define endl '\n'
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using tp=tuple<int,int>;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;ll d;
		cin>>n>>d;
		vl x(n);
		for(ll&v:x)cin>>v;
		if(1<=c&&c<=10){
			ll ans=0;
			for(int i=0;i<n;i++){
				vi dis(n,1e9),cnt(n);
				cnt[i]=1,dis[i]=0;
				int sum=1;
				int l=i,r=i;
				for(int j=i+1;j<n;j++){
					while(l<=r&&x[j]-x[l]>d)sum-=cnt[l],l++;
					if(l>r)break;
					if(sum<=0){
						sum=0;
						for(int k=l;k<=r;k++){
							if(dis[k]==dis[l])sum+=cnt[k];
							else break;
						}
					}
					dis[j]=dis[l]+1;
					cnt[j]=sum;
					r++;
				}
				for(int j=i+1;j<n;j++)if(cnt[j]==2)ans++;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==1){cout<<0<<endl;continue;}
		if(c==11||c==12){
			ll o=x[1]-x[0];
			if(d<o*2||d/o>=n-1){cout<<0<<endl;continue;}
			int o2=d/o;
			cout<<max(n-(o2*2-1),0)<<endl;
			continue;
		}
		if(c==13||c==14){
			int mid=-1;
			for(int i=0;i<n;i++){
				if(x[i]-x[0]<=d&&x[n-1]-x[i]<=d){mid=i;break;}
			}
			//vi jp(n,-1);
			vi jl(n),jr(n);
			for(int i=mid-1,p=n-1;i>=0;i--){
				while(p>i&&x[p]-x[i]>d)p--;
				if(p!=i)jl[p]++;
			}
			for(int i=mid+1,p=0;i<n;i++){
				while(p<i&&x[i]-x[p]>d)p++;
				if(p!=i)jr[p]++;
			}
			ll ans=0;
			for(int i=0;i+1<n;i++)ans+=(ll)jr[i]*jl[i+1];
			cout<<ans<<endl;
			continue;
		}
		vi jl(n),jr(n);
		for(int i=n-1,p=n-1;i>=0;i--){
			while(p>i&&x[p]-x[i]>d)p--;
			if(p!=i)jl[p]++;
		}
		for(int i=0,p=0;i<n;i++){
			while(p<i&&x[i]-x[p]>d)p++;
			if(p!=i)jr[p]++;
		}
		ll ans=0;
		for(int i=0;i+1<n;i++)ans+=(ll)jr[i]*jl[i+1];
		cout<<ans<<endl;
	}
	
	return 0;
}