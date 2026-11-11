#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pir;
const int MAXN=2e6+5,mod=998244353,inf=0x3f3f3f3f;
int testid,T;
int n,a[MAXN],d;
struct status{
	int x,b;
	void upd(const status &o){
		if(x<o.x+1)
			return ;
		else if(x==o.x+1)
			b+=o.b;
		else
			x=o.x+1,b=o.b;
	}
}f[MAXN];
inline bool ok(int x,int y){
	return a[y]-a[x]<=d;
}
void subtask0(){
	int ans=0;
	for(int i=4;i<=n;i++){
		if(!ok(i-1,i))
			continue;
		f[i]={0,1};
		f[i-1]={1,1};
		if(!ok(i-2,i-1))
			continue;
		f[i-2]={1+!ok(i-2,i),1};
		for(int j=i-3,k=i;j>=1;j--){
			while(k>j&&!ok(j,k))
				--k;
			if(j==k)
				break;
			f[j]={f[k].x+1,f[k].b};
			if(k-1>j)
				f[j].upd(f[k-1]);
			if(k-2>j)
				f[j].upd(f[k-2]);
			ans+=(f[j].b==2);
		}
	}
	cout<<ans<<"\n";
}
void subtaskA(){
	int ans=0;
	int p=d/(a[2]-a[1]);
	if(p<2){
		cout<<"0\n";
		return ;
	}
	for(int i=p+2;i<=n;i++)
		ans+=(i-p-1)/p+((i-p)%p==p-1);
	cout<<ans<<"\n";
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(11<=testid&&testid<=12)
		return subtaskA();
//	if(testid<=10)
		return subtask0();
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>testid>>T;
	while(T--)
		solve();
	return 0;
}

