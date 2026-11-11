#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
namespace CSPS{
	int n,m;
	int a[2000005];
	int r[2000005];
	struct INFO{
		int mn,cnt; 
	};
	INFO operator+(INFO x,INFO y){
		INFO ans={0,0};
		ans.mn=min(x.mn,y.mn);
		if(ans.mn==x.mn)ans.cnt+=x.cnt;
		if(ans.mn==y.mn)ans.cnt+=y.cnt;
		return ans;
	}
	struct SGT{
		INFO he[500005];
		void add(int x,INFO v,int l=1,int r=n,int k=1){
			if(l==r){
				he[k]=v;
				return;
			}
			int mid=l+r>>1;
			if(x<=mid)add(x,v,l,mid,k<<1);
			else add(x,v,mid+1,r,k<<1|1);
			he[k]=he[k<<1]+he[k<<1|1];
		}
		INFO query(int L,int R,int l=1,int r=n,int k=1){
			if(L>r||l>R)return {INT_MAX,0};
			if(L<=l&&r<=R)return he[k];
			int mid=l+r>>1;
			return query(L,R,l,mid,k<<1)+query(L,R,mid+1,r,k<<1|1);
		}
	}t;
	void solve(int TC){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(TC==11||TC==12){//µÈ²îÊýÁÐ 
			int gc=a[2]-a[1];
			gc=m/gc;
			if(gc<=1)return cout<<0<<endl,void();
			gc=2*gc;
			int ans=0;
			for(int i=gc;i<=n;i++)ans++;
			return cout<<ans<<endl,void();
		}else if(TC<=10){//
			for(int i=1;i<=n;i++){
				r[i]=i;
				for(;r[i]<=n;r[i]++){
					if(a[r[i]]>a[i]+m)break;
				}
				r[i]--;
			}
			int ans=0;
			for(int i=3;i<=n;i++){
				for(int j=1;j<=n;j++)t.add(j,{INT_MAX,0});
				t.add(i,{0,1});
				for(int j=i-1;j>=1;j--){
					INFO u=t.query(j+1,min(r[j],i));
					if(u.cnt==2)ans++;
					u.mn++;
					t.add(j,u);
				}
			}
			cout<<ans<<endl;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,Q=1;
	cin>>c>>Q;
	while(Q--)CSPS::solve(c);
//while(1);
	return 0;
}
/*

s 1024MB
s 39MB
*/

