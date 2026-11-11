#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,minn=1e9,a[200010];
int ans;
void dfs(int now,int choose,int num){
	if(now+(m-choose)>n)	return;
	if(now==n&&choose<m)	return;
	if(choose==m){
		ans=max(ans,num);
		return;
	}
	for(int i=now+1;i<=n;i++)	dfs(i,choose+1,num&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i],maxn=max(maxn,a[i]);
	if(n>2000){
		if(maxn<=4){
			cout<<2;
			return 0;
		}
		if(m==n-1){
			for(int i=1;i<=n;i++){
				if(i==1){
					int pre=a[2];
					for(int j=3;j<=n;j++)	pre&=a[i];
					ans=max(pre,ans);
				}	
				else{
					int pre=a[1];
					for(int j=2;j<=n;j++)
						if(i!=j)
							pre&=a[i];
					ans=max(pre,ans);
				}		
			}
			cout<<ans;
			return 0;	
		}
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)	dfs(i,1,a[i]);
	cout<<ans;
	return 0;
}