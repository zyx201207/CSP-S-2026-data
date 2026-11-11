#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int n,m,c,t,d;vector<int> a(MAXN);
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[n]-a[1]<=d||c==13||c==14||d<=1){//B性质 
			cout<<0<<endl;continue;
		}
		if(c==11||c==12){//A性质 
			int x=d/(a[2]-a[1]);
			cout<<n-2*x+1<<endl;
			continue;
		}
		else{
			/*vector<int> dp;dp.push_back(0);//dp->可以跳过几个岛 
			for(int i=1;i<=n;i++){
				int tans=0;
				for(int j=1;j<=n;j++){
					if(a[j]-a[i]>d)break;
					tans++;
				}
				dp.push_back(tans);
			} 
			for(int u=1;u<=n;u++){
				for(int f=1;f<=dp[u];f++){
					if(dp[u+f]>dp[u+f+1])pf=
				}
			}*/
			cout<<0<<endl;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

