#include<bits/stdc++.h>
#define int long long
using namespace std;

bool st;
constexpr int N=2e6+5,M=22;
int c,t,n,d;
int x[N];

namespace subtask1{
	constexpr int N1=5005,inf=0x3f3f3f3f3f3f;
	class Nygglatho{
	public:
		int val,cnt;
		Nygglatho(){ val=inf,cnt=0;}
		Nygglatho(int _val,int _cnt){ val=_val,cnt=_cnt;}
		Nygglatho operator + (const Nygglatho &Ny) const{
			Nygglatho ans;
			ans.val=min(val,Ny.val);
			ans.cnt=(val==Ny.val?cnt+Ny.cnt:(val>Ny.val)?Ny.cnt:cnt);
			return ans;
		}
	}dp[N1];
	class Nikaidou{
	public:
		Nygglatho tr[N1];
		void init(){ for(int i=1;i<=n;i++) tr[i]=Nygglatho();}
		int lowbit(int x){ return x&(-x);}
		void update(int x,Nygglatho k){ for(;x;x-=lowbit(x)) tr[x]=tr[x]+k;}
		Nygglatho query(int x){ Nygglatho ans; for(;x<=n;x+=lowbit(x)) ans=ans+tr[x]; return ans;}
	}T;
	int solve(){
		int ans=0;
		for(int i=1;i<=n;i++){
			T.init();
			for(int j=1;j<=n;j++) dp[j]=Nygglatho();
			dp[i]=Nygglatho(0,1);
			T.update(i,dp[i]);
			for(int j=i+1;j<=n;j++){
				int pos=lower_bound(x+1,x+n+1,x[j]-d)-x;
//				cerr<<pos<<endl;
				dp[j]=T.query(pos);
				dp[j].val+=1;
				T.update(j,dp[j]);
				if(dp[j].cnt==2) ans++;
			}
//			cerr<<endl;
		}
		return ans;
	}
}

namespace subtaska{
	int solve(){
		int ans=0,cha=x[2]-x[1];
		if((ans/cha)>2||(ans/cha)<=1) return 0;
		if(n<4) return 0;
		int tar=n-(n&1);
		ans=(n+1)*((tar/2)-1)-((tar/2)*((tar/2)+1)/2-1);
		return ans;
	}
}

namespace subtaskb{
	int solve(){
		int tar=0,ans=0;
		for(int i=1;i<=n;i++) if(x[i]-x[1]<=d&&x[n]-x[1]<=d){ tar=i; break;}
		for(int i=1;i<tar;i++){
			int j=upper_bound(x+1,x+n+1,x[i]+1)-x;
			if((j-1>tar||j+1<tar)&&j<=n) ans+=j-tar;
		}
		return ans;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(;t--;){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c<11) cout<<subtask1::solve()<<'\n';
		else if(c<13) cout<<subtaska::solve()<<'\n';
		else cout<<subtaskb::solve()<<'\n';
	}
}
