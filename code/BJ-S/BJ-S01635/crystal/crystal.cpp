#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
#define pub push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const int DC=0;
const ll mod=0;
const int N=0;

int _c;
int n;
ll m,a[500005],s[500005];
bool chk(int l,int r,ll v){return s[r]-s[l-1]+m>=v*(r-l+1);}

void INIT(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);}
void SOLVE(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,res=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(chk(mid,i,a[i]))res=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	INIT();
	int T;
	if(DC)cin>>_c>>T;else T=1;
	for(int _=1;_<=T;_++)SOLVE();
	return 0;
}