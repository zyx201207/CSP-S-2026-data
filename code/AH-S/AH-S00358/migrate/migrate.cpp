#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e6+10;
int n;
ll d;
ll a[maxn];

struct STA{
	vector < pair<ll,int> >b;
	int l=1,r=0;
	STA(int n):b(n+10){}
	void init(){
		l=1,r=0;
	}
	void insert(ll x,int v){
		while(l<=r && b[l].first-x>d) ++l;
		while(l<=r && b[r].second > v) --r;
		b[++r] = {x,v};
		return ;
	}
	int query(ll x){
		while(l<=r && b[l].first-x>d) ++l;
		if(!(l<=r)) return -1;
		return b[l].second;
	}
};

namespace c1{
	vector<int> s;
	vector<int> t;
	vector<ll> vis;
	STA sta(n);
	
	void solve(){
		int ans=0;
		for(int i=2;i<=n;i++){
			s.assign(n+10,n+5);
			t.assign(n+10,0);
			vis.assign(n+10,0);
			sta.init();
			
			sta.insert(a[i],0);
			int k=1;
			for(int j=i-1;j>=1;j--){
				int minn=sta.query(a[j]);
				if(minn==-1){
					k=j+1;
					break;
				}
				s[j]=minn+1;
				sta.insert(a[j],s[j]);
			}
			t[0]++;
			for(int l=i-1,r=i ; l>=k;l--){
				while(a[r]-a[l]>d){ t[s[r]]-=vis[r];--r;}
				if(t[ s[l]-1 ]==2) ++ans;
				vis[l]=t[s[l]-1];
				t[s[l]]+=vis[l];
				
			}
			
			//cout<<i<<" "<<ans<<"\n";
			/*
			
			for(int j=1;j<i;j++) cout<<s[j]<<" ";
			cout<<"\n";
			* */
			
		}
		cout<<ans<<"\n";
	}
}

namespace c2{
	void solve(){
		ll dis=a[2]-a[1];
		
		//cout<<dis<<" "<<n<<" "<<d<<"\n";
		
		if(d/dis<=1) cout<<"0\n";
		else{
			cout<<max((ll)0,n-((d/dis)*2-1))<<"\n";
		}
		
	}
}


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		if(n==1) cout<<"0\n";
		else if(c==0) c2::solve();
		else if(c<=10) c1::solve();
		else if(c==11 || c==12) c2::solve();
		else if(c==13 || c==14) cout<<"0\n";
	}
	return 0;
}
