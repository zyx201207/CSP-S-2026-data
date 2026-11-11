#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+9;
int n,m,a[MAXN],sum,an,maxx=-1;
int ans;
void dfs(int step,int sum,int choose){
	if(choose==m){
	 	if(ans<sum) ans=sum;
	 	//cout<<ans<<endl;
	 	return ;
	}
	if(step==n+1) return ;
	dfs(step+1,sum,choose);
	if(choose==0) dfs(step+1,a[step],choose+1);
	else dfs(step+1,sum&a[step],choose+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	else{
		sum=a[1];
		for(int i=2;i<=n;i++) sum&=a[i],maxx=max(maxx,a[i]);
		maxx=max(maxx,a[1]);
		if(m==n) cout<<sum;
		else if(m==1) cout<<maxx;
		else if(m==n-1){
			for(int i=1;i<=n;i++) an=max(an,sum&a[i]);
			cout<<an;
		}
		else if(m==2){
			int res=0;
			for(int i=1;i<=n;i++) 
				for(int j=i+1;j<=n;j++)
				res=max(res,a[i]^a[j]);
			cout<<res;
		}
	}
	return 0;  
}
//4 2 3 15 12 12
//5 3 31 3 1 15 7
//21 2 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21