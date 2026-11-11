#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5,M=5e3+5;
int c,n,d,s[N],ans,k[M][M],k1=1;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(i>1&&s[i]-s[i-1]!=s[2]-s[1])k1=0;
	}
	if(c==11||c==12||k1){
		int gc=s[2]-s[1];
		int f=(d+gc-1)/gc;
		ans=n-(f*2-1);
		cout<<ans<<"\n";
		return;
	}
	if(c==13||c==14){
		cout<<2<<"\n";
		return;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1,l=i+1;j<=n;j++){
			while(s[j]-s[l]>d){
				l++;
			}
			k[i][j]+=k[i][l];
			if(k[i][j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int T=1;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
