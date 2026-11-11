#include<bits/stdc++.h>
using namespace std;
int n,m,a[2005],ans;
void dfs(int cnt,int x){
	if(cnt==m){
		ans=max(ans,x);
		return;
	}
	for(int i=2;i<=n;i++){
		dfs(cnt+1,x&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++)
		    cin>>a[i];
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(0,a[1]);
		cout<<ans;
	}
	return 0;
} 
