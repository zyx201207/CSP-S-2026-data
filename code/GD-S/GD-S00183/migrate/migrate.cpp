#include<iostream>
#define int long long
using namespace std;
int x[100005];
int l[100005];
int r[100005];
int a[100005];
int b[100005];
void solve(){
	int n,d;
	cin>>n>>d;
	x[0]=-4e18;
	x[n+1]=4e18;
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		x[i]=t;
	}int las=0;
	for(int i=1;i<=n+1;i++){
		while(x[i]-x[las]>d){
			r[las]=i-1;
			las++;
		}
		
	}las=n+1;
	for(int i=n;i>=0;i--){
		while(x[las]-x[i]>d){
			l[las]=i+1;
			las--;
		}
	}
	int final=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
				a[cnt]=0;
				b[cnt]=0;
				cnt++;
			}
			int x=i;
			cnt=0;
			bool bo=1;
			while(x<j){
				a[++cnt]=x;
				if(r[x]==x){
					bo=0;
					break;
				}
				x=r[x];
			}int y=j;
			cnt=0;
			if(!bo)continue;
			while(y>i){
				b[++cnt]=y;
				y=l[y];
			}
			int sum=1;
			bo=0;
			for(int k=2;k<=cnt;k++){
				if(a[k]-b[cnt-k+2]+1>2){
					bo=1;
					continue;
				}
				sum*=a[k]-b[cnt-k+2]+1;
				if(sum>2){
					bo=1;
					continue;
				}
			}
			if(!bo and sum==2){
				final++;
			}
		}
	}for(int i=0;i<=n+1;i++){
		l[i]=0;
		r[i]=0;
		x[i]=0;
	}
	cout<<final<<'\n';
	return ;
}
signed main(){

    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
