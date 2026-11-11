#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define int ll
const int N=2e6+5;//=2^21
const int B=25;
int n,d,a[N];
int /*l[N],*/r[N];
//int lskip[N][B];
int rskip[N][B];
int ans;
int dis(int x,int y){
	if(rskip[x][21]<y){
		return -1;
	}
	int nw=x,res=0;
	for(int i=21;i>=0;i--){
		if(rskip[nw][i]<y){
			res+=(1ll<<i);
			nw=rskip[nw][i];
		}
	}
	return res+1;
}
int sumto;
bool flag;
void dfs(int nw,int to,int lst){
	if(flag){
		return ;
	}
	if(nw==to&&lst==0){
		sumto++;
		if(sumto>=3){
			flag=1;
		}
		return ;
	}
//	if(dis(nw,to)>lst){
//		return ;
//	}
	if(lst<=0){
		return ;
	}
	for(int nxt=r[nw];nxt>=nw+1;nxt--){
		if(dis(nxt,to)>lst){
			break;
		}
		dfs(nxt,to,lst-1);
	}
	return ;
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	sort(a+1,a+1+n);
	int p;
	p=1;
	for(int i=1;i<=n;i++){
		while(a[p+1]-a[i]<=d&&p+1<=n){
			p++;
		}
		r[i]=p;
	}
//	p=n;
//	for(int i=n;i>=1;i--){
//		while(a[i]-a[p-1]<=d&&p-1>=1){
//			p--;
//		}
//		l[i]=p;
//	}
	for(int i=1;i<=n;i++){
//		lskip[i][0]=l[i];
		rskip[i][0]=r[i];
	}
	for(int j=1;j<=21;j++){
		for(int i=1;i<=n;i++){
//			lskip[i][j]=lskip[lskip[i][j-1]][j-1];
			rskip[i][j]=rskip[rskip[i][j-1]][j-1];
		}
	}
//	cerr<<dis(1,n);
	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sumto=0;
			flag=0;
			dfs(i,j,dis(i,j));
			if(sumto==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}

