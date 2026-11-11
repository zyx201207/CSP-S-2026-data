#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=-1;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int x,int z,int y){
	if(x>n){
		if(y==m)
			ans=max(ans,z);
		return ;
	}
	if(y>m)return;
	if(z<ans)return ;
	dfs(x+1,z&a[x],y+1);
	dfs(x+1,z,y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	if(m==1){
		ans=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
	}
	else if(m==n){
		cin>>a[1];
		ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=ans&a[i];
		}
	}
	else if(m==2){
		ans=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
	}
	else {
		int cnt=0,mx=-1;
		cin>>a[1];
		ans=a[1];
		if(a[1]<4&&a[1]>=0)cnt++;
		mx=max(mx,a[1]);
		for(int i=2;i<=n;i++){
			cin>>a[i];
			if(a[i]<4&&a[i]>=0)cnt++;
			mx=max(mx,a[i]);
			ans=ans&a[i];
		}
		bool flag=1;
		while(ans>=2){
			if(ans%2==1){
				flag=0;
			}
			ans/=2;
		}
		sort(a+1,a+n+1,cmp);
		if(flag){
			ans=a[1];
		}
		else {
			if(cnt==n){
				int b[4];
				for(int i=1;i<=n;i++){
					b[a[i]]++;
				}
				if(a[1]==a[2]){
					ans==a[1];
				}
				else{
					if(mx==3&&b[2]>0){
						ans=2;
					}
					else if(b[1]>0&&b[3]>0){
						ans=1;
					}
					else ans=0;
				}
			}
			else{
				dfs(2,a[1],1);
			}
		}
	}
	cout<<ans;
	return 0;
} 
