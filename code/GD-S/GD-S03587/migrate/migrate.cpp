#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000100;
int c,T,n,d,a[N],ri[N];
int ans;
int find(int x){
	int l=x,r=n,res=x;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]-a[x]<=d) res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}
inline void solve(int l,int r){
	for(int u=l;u<=r;u++){
		for(int v=u+1;v<=r;v++){
			int now=u,cnt=0;
			while(now<v){
				if(ri[now]>=v){
					ans+=cnt;
					break;
				}else{
					int vv=ri[now];
					int vvv=min(v,ri[vv]);
					if(vv-now>1 && ri[vv-1]>=vvv) cnt++;
					if(cnt==2 || (vv-now>2 && ri[vv-2]>=vvv)) break;
					now=vv;
				}
			}
		}
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=2){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++) ri[i]=find(i);
		if(t==11 || t==12){
			int r=a[2]-a[1];
			int t=d/r;
			//cout<<r<<' '<<d<<' '<<t<<'\n';
			if(!t || t==1){
				cout<<0<<'\n';
				continue;
			}
			for(int i=2*t-1;i<=2*t-1;i+=t){
				int l=1,r=n-i;
				ans+=max(r-l+1,0ll);
			//	cout<<ans<<'\n';
			}
			cout<<ans<<'\n';
		}else if(c==13 || c==14){
			int mid=n;
			for(int i=n;i>=1;i--) if(ri[i]==n) mid=i;
			for(int i=1;i<mid;i++){
				int v=ri[i];
				if(v!=mid+1) continue;
				ans+=n-ri[mid-1];
			}
			cout<<ans<<'\n';
		}else{
			int lst=1;
			for(int i=1;i<=n;i++){
				if(ri[i]==i){
					solve(lst,i);
					lst=i+1;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
±»´´·ÉÁ¦ 
*/
