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
const int DC=1;
const ll mod=0;
const int N=2000005;

int _c;
int n,sumn;
ll d,a[N];
int cnt[N];
int fa[N],tp[N];
int s0[N],s1[N],c0[N];
ll ans;

void INIT(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);}
void SOLVE(){
	cin>>n>>d;
	sumn+=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fa[i]=tp[i]=s0[i]=s1[i]=cnt[i]=c0[i]=0;
	}
	a[n+1]=a[n]+d+1;
	a[0]=a[1]-d-1;
	for(int i=1,r=1;i<=n;i++){
		while(a[r+1]<=a[i]+d)++r;
		// s0[i]++,s1[i]++;
		if(r>i){
			fa[i]=r;
			tp[i]=cnt[r]++;
			++s0[r];++s1[r];
			if(tp[i]==0){
				c0[r]=i;
				s0[r]+=s0[i];
				s1[r]+=s1[i];
			}
			if(tp[i]==1){
				s1[r]+=s0[i];
				if(c0[c0[r]]>0){
					s1[r]-=s0[c0[i]];
				}
			}
		}
		// cerr<<i<<": "<<fa[i]<<" "<<tp[i]<<" "<<s0[i]<<" "<<s1[i]<<"\n";
	}
	ans=0;
	for(int i=1,l=1;i<=n;i++){
		while(a[l]<a[i]-d)++l;
		if(l<i){
			// ans+=ss0[i-1]-ss0[l];
			if(i>=l+2){
				ans+=s0[l+1];
				if(c0[l]>0){
					ans-=s0[c0[l+1]];
				}
			}
			ans+=s1[l]-s0[l];
			// cerr<<i<<": "<<l<<" "<<s0[l]<<" "<<s1[l]<<" | "<<s0[l+1]<<" "<<c0[l]<<" "<<c0[l+1]<<" "<<s0[c0[l+1]]<<" awa\n";
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	INIT();
	int T;
	if(DC)cin>>_c>>T;else T=1;
	for(int _=1;_<=T;_++)SOLVE();
	// cerr<<sumn<<"\n";
	return 0;
}