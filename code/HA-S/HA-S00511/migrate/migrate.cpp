#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
const int M=310;
int C,T;
int n,d,a[N],s[M][M],c[M][M];
void solve()
{
	if(C==11||C==12){
		int gc=a[n]-a[n-1];
		if(d<2*gc) cout<<0<<'\n';
		else if(d>=2*gc){
			int t=d/gc;
			t=t+(t-1);
			cout<<n-t<<'\n';
		}
	}else if(n<=305){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int t=a[i]-a[j];
				if(t<0) t=-t;
				if(t<=d) c[i][j]=s[i][j]=1;
				else c[i][j]=s[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++){
					if(s[i][k]&&s[k][j]&&!s[i][j]) s[i][j]=s[i][k]+s[k][j],c[i][j]++;
					else if(s[i][k]&&s[k][j]&&s[i][k]+s[k][j]==s[i][j]) c[i][j]++;
					else if(s[i][k]&&s[k][j]&&s[i][k]+s[k][j]<s[i][j]) s[i][j]=s[i][k]+s[k][j],c[i][j]=1;
				}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(c[i][j]==2) cnt++;
		cnt/=2;
		cout<<cnt<<'\n';
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		solve();
	}
	return 0;
}
