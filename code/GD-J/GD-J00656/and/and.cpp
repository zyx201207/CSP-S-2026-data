#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ma,moumoumou,ans;
bool book[200005];
void dfs(int step,int s,int sum){
	if(step>n){
		//cout<<step<<" "<<s<<" "<<sum<<endl;
		if(s==m){
			ans=max(ans,sum);
			
		}
		return;
	}
	if(s>m) return;
	for(int i=1;i<=n;i++){
		
		dfs(step+1,s,sum);
		if(!book[i]){
			int ssum;
			if(s==0) ssum=a[i];
			else ssum=sum&a[i];
			book[i]=1;
			//cout<<step<<" "<<s<<" "<<sum<<" "<<i<<endl;
			dfs(step+1,s+1,ssum);
			book[i]=0;
		}
		
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(i!=1) moumoumou=moumoumou&a[i];
		else moumoumou=a[i];
	}
	if(m==1) cout<<ma;
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++) ans=max(ans,moumoumou&a[i]);
		cout<<ans;
	}
	else{
		dfs(1,0,0);
		cout<<ans;
		//cout<<(a[2]&a[3]);
	}
	return 0;
}
