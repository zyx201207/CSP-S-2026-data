#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;

int n;
ll d,a[maxn];
int Get(int x){
	int l=x,r=n+1,mid;
	while(l+1<r){
		mid=(l+r)>>1;
		if(a[mid]-a[x]<=d) l=mid;
		else r=mid;
	}
	return l;
}

namespace subA{
	bool Chk(){
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return false;
		}
		return true;
	}
	void Main(){
//		cout<<a[2]-a[1]<<" "<<d<<"\n";
//		cout<<Get(1)<<" -\n";
		if(Get(1)<=2){
			cout<<"0\n"; return;
		}
		ll ans=0,len=Get(1)-1;
//		cout<<len<<"\n";
		for(int i=1;i+len<=n;i++){
			if((n-i)/len>=2) ans++;
//			ans+=(n-i)/len-1;
			else if((n-i)%len==len-1) ans++;
		}
		cout<<ans<<"\n";
	}
} 

namespace subbl{
	const int maxn=5005,INF=1e9;
	
int f[maxn][maxn],cnt[maxn][maxn];
	void Main(){
		memset(f,0x3f,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			int tmp=Get(i);
//			cout<<tmp<<" ";
			for(int j=i+1;j<=tmp;j++) f[i][j]=1,cnt[i][j]=1;
			f[i][i]=1,cnt[i][i]=1;
//			if(i!=tmp) f[i][tmp]=1;
		}
//		cout<<"\n";
		ll ans=0;
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				int j=i+len-1;
				for(int k=i+1;k<j;k++){
					if(cnt[i][k]>2||cnt[k][j]>2) continue;
					if(f[i][k]+f[k][j]<f[i][j]) f[i][j]=f[i][k]+f[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
					else if(f[i][k]+f[k][j]==f[i][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
				if(f[i][j]<INF) ans+=(cnt[i][j]==2);
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<cnt[i][j]<<" ";
//			}
//			cout<<"\n";
//		}
//		cout<<"\n";
		cout<<ans<<"\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T; cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(subA::Chk()){
//			cout<<"OK\n";
			subA::Main();
		}
		else if(n<=305){
			subbl::Main();
		}
//		cout<<Get(2)<<"\n";
		else{
		ll ans=0;
		for(int i=1;i<=n;i++){
			int tmp=Get(i),cnt=0,nw=tmp;
			if(tmp==i) continue;
//			cout<<nw<<"\n";
			while(cnt<2){
				tmp=Get(nw);
				if(tmp==nw) break;
				int tmp2=Get(nw-1);
				if(tmp2<nw) break;
//				if(cnt>=2) break;
				if(cnt==1){
//					if(tmp==tmp2) ans+=tmp2-Get(nw-2);
					ans+=tmp-tmp2;
				}
				if(!cnt) ans+=tmp2-max(nw,Get(nw-2));
				if(Get(nw-2)==tmp) break;
				if(tmp2==tmp) cnt++;
				nw=tmp;
//				cout<<ans<<" -- \n";
//				cout<<nw<<"\n";
			}
//			cout<<ans<<"\n";
//			cout<<"\n";
		}
		cout<<ans<<"\n";
		}
	}
	return 0;
}
