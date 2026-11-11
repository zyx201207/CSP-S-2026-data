#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m;
int a[N],s[N],maxx=-1;
int ans=-1;
void dfs(int step,int cnt,int sum){
	if(s[step]&sum<=ans) return ;
	if(cnt>m) return ;
	if(step<m-cnt) return ;
	if(cnt<m&&step==0) return ;
	if(step==0&&cnt==m){
		ans=max(ans,sum);
		return ;
	}
	dfs(step-1,cnt+1,(sum&a[step]));
	dfs(step-1,cnt,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[n+1]=a[n];
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]&a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=20){
		dfs(n,0,a[n]);
		cout<<ans;
	}else if(m==n){
		cout<<s[1];
	}else if(m==1){
		cout<<maxx;
	}else if(m==2){
		maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}else if(2000<n&&n<=200000){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
} 
/*
4 2
3 15 12 12
*/
