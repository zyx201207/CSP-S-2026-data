#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=2000010;
int c,t,n;
long long d,x[N],ne[N],pr[N];
vector<int> ve;
int work(int u,int v){
	ve.clear();
	ve.push_back(u);
	int p=u;
	while(p!=v){
		if(ne[p]==p) return 0;
		else if(ne[p]>=v) p=v;
		else{
			p=ne[p];
			ve.push_back(p);
		}
	}
	ve.push_back(v);
	int cnt=0,len=ve.size();
	int i=len-1;
	for(;i>=3;i--){
		if(pr[ve[i]]!=ve[i-1]){
			if(ve[i-1]-pr[ve[i]]==1&&cnt==0&&pr[ve[i-1]]==ve[i-2]){
				cnt++;
				i--;
			}else{
				return 0;
			}
		}
	}
	if(i==2){
		if(pr[ve[i]]!=ve[i-1]){
			if(ve[i-1]-pr[ve[i]]==1&&cnt==0) cnt++;
			else return 0;
		}	
	}
	if(cnt==1) return 1;
	else return 0;
}
void solve1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&x[j+1]-x[i]<=d) j++;
		ne[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j>1&&x[i]-x[j-1]<=d) j--;
		pr[i]=j;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=work(i,j);
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	int dd=x[2]-x[1];
	if(d<2*dd) cout<<0<<"\n";
	else cout<<max(0ll,n-d/dd*2+1)<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c<=10) while(t--) solve1();
	else if(c<=12) while(t--) solve2();
	return 0;
}