#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5,MAXM=5e3+5;
int c,t,n,dp[MAXM][MAXM],ok[MAXM][MAXM],far[MAXN];
long long d,x[MAXN],ans;
void solve(){
	ans=0;
	for(int i=1;i<=n;i++){
		int lf=i;
		dp[i][i]=i;
		while(lf<n){
			int lst=lf;
			while(lst!=n+1&&x[lst]-x[lf]<=d){
				lst++;
			}
			if(lst==lf+1){
				for(int j=lf+1;j<=n;j++){
					dp[i][j]=0;
				}
				break;
			}
			for(int j=lf+1;j<lst;j++){
				dp[i][j]=lf;
			}
			lf=lst-1;
		}
	}
	int lst=n;
	for(int i=n;i>=1;i--){
		while(lst!=0&&x[i]-x[lst]<=d){
			lst--;
		}
		far[i]=lst+1;
	//	cout<<i<<" "<<far[i]<<" "<<lst<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ok[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dp[i][j]-max(i,far[j])==1&&(ok[i][dp[i][j]]||ok[i][max(i,far[j])])){
				ok[i][j]=2;
				continue;
			}
			if(dp[i][j]-max(i,far[j])==1){
				ok[i][j]=1;
				ans++;
			}
			if(dp[i][j]==max(i,far[j])&&ok[i][dp[i][j]]==1){
				ok[i][j]=1;
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
void solve2(){
	ans=0;
	long long num=d/(x[2]-x[1]);
	if(num<=1){
		cout<<0<<'\n';
		return ;
	}
	cout<<max(0ll,n-2*num+1)<<'\n';
}
void solve31(int lst,int str){
	for(int i=1;i<str;i++){
		if(far[i]==str+1){
			ans+=n-far[str-1];
		}
		else if(far[i]==str){
			ans+=far[str-1]-far[str-2];
		}
	}
	cout<<ans<<'\n';
}
void solve32(int lst,int str){
	for(int i=1;i<lst;i++){
		if(far[i]==str){
			ans+=n-far[lst-1];
		}
	}
	cout<<ans<<'\n';
}
void solve3(){
	int lst=n;
	while(lst!=0&&x[n]-x[lst]<=d){
		lst--;
	}
	lst++;
	int str=1;
	while(str!=n+1&&x[str]-x[1]<=d){
		str++;
	}
	str--;
	ans=0;
//	cout<<str<<" "<<lst<<'\n';
	int nxt=1;
	for(int i=1;i<=n;i++){
		while(nxt!=n+1&&x[nxt]-x[i]<=d){
			nxt++;
		}
		far[i]=nxt-1;
	}
	if(str==lst){
		solve31(lst,str);
	}
	else if(str-lst==1){
		solve32(lst,str);
	}
	else{
		cout<<0<<'\n';
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
//		solve3();
		if(c<=10){
			solve();
		}
		if(c>=11&&c<=12){
			solve2();
		}
		if(c>=13&&c<=14){
			solve3();
		}
	}
	return 0;
}

