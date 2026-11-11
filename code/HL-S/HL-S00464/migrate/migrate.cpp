#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000009],sum=0,book[2000009],minn=99999999,ans;
void dfs(int i,int j,int step){
	if(i==j&&step<minn){
		minn=step;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0&&abs(a[i]-a[j])<=d){
			book[i]=1;
			dfs(i,j,step+1);
			book[i]=0;
		}
	}
}
void dfs1(int i,int j,int step){
	if(i==j&&step==minn){
		sum++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(book[i]==0&&abs(a[i]-a[j])<=d){
			book[i]=1;
			dfs(i,j,step+1);
			book[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				book[i]=1;
				dfs(i,j,0);
				dfs1(i,j,0);
				book[i]=0;
				if(sum==2){
					ans++;
				}
				sum=0;
				minn=0;
				memset(book,0,sizeof(book));
			}
		}
		cout<<ans<<endl;
		t--;
	}
	dfs(1,4,0);
	cout<<sum;
	return 0;
}