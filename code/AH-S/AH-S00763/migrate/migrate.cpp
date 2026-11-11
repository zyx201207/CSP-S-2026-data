#include<bits/stdc++.h>
#define MAXN (int)2e6 + 10
using namespace std;
int n,d,x[MAXN],latest[MAXN],lowest[MAXN];
void HeHNCu(){
	memset(latest,0,sizeof latest);
	memset(lowest,0,sizeof lowest);
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int l=1,r=1;
	for(;l<=n;){
		while(r<n && (x[r + 1] - x[l] <=d))r++;
		latest[l] = r;l++;
	}
	r = l = n;
	for(;r>=1;){
		while(l> 1 && (x[r] - x[l - 1] <=d))l--;
		lowest[r] = l;r--;
	}
	//for(int i=1;i<=n;i++)cout<<latest[i]<<' '<<lowest[i]<<endl;
	int ans = 0;
	if(n > 300)
		for(int i=1;i<=n;i++){
			for(int j = i + 3;j<=n;j++){
				if((x[j] - x[i] > d )&& (latest[i] - lowest[j] == 1))ans++; 
			}
		}
	else
		for(int i=1;i<=n;i++){
			for(int j = latest[i] + 1;j<=n;j++){			
				int cnt = 0;
				for(int k = i + 1;k < j;k ++)if(x[k] - x[i] <= d && x[j] - x[k] <= d)cnt++;
				if(cnt == 2)ans++;
			}
		}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)HeHNCu();
	return 0;
}
