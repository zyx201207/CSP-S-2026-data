#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x;
	bool has[35];
	int st=1;
}a[500005];
int dp[500005][35];
int flag[500005];
int n,m;
int maxl=-1;
int check(int x,int pos){
	int flag=0;
	while(x){
		if(x&1){
			a[pos].has[flag]=1;
		}
		x/=2;
		flag++;
	}
	maxl=max(maxl,flag-1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		check(a[i].x,i);
	}	
	int cnt=0,ans=0;
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i].has[j]&&a[i].st){
				cnt++;
				flag[cnt]=i;
				a[i].st=2;
			}
		}
		if(cnt<m)continue;
		for(int i=1;i<=n;i++){
			if(a[i].st==2)a[i].st=1;
			else a[i].st=0;
		}
		if(j==0)ans++;
		else ans+=(2<<(j-1));
		//cout<<ans<<" "<<j<<" "<<cnt<<endl;
	}
	cout<<ans;
	return 0;
}
