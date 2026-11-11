#include<bits/stdc++.h>
using namespace std;
#define MAXN 200010
#define MAXM 35
typedef long long ll;
int n,m;
ll a[MAXN],ans;

inline void read(ll &x){
	char ch=getchar();int f=1;x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+(ch^48);
	x*=f;
}

void fileIO(const string& s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

bool del[MAXN];
void solve(){
	for(int i=MAXM;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)if(!del[j])cnt+=((a[j]>>i)&1);
		if(cnt>=m){
			ans+=(1<<i);
		    for(int j=1;j<=n;j++)if((!del[j])&&(!((a[j]>>i)&1)))del[j]=1;
		}
	}
}

int main(){
	fileIO("and");
	cin>>n>>m;
	for(int i=1;i<=n;i++)read(a[i]);
	
	solve();
	cout<<ans;
	return 0;
}
