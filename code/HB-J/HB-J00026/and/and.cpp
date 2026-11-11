#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxn,modyo=1,maxy;
bool book[200010];
void dfs(int x,int sum){
	if(x==n+1||sum==0){
		int cnt=0;
		if(sum==0){
			int ans;
			for(int i=1;i<=n;i++){
				if(book[i]==1){
					ans=a[i];
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(book[i]==1){
					ans=ans&a[i];
					//cout<<a[i]<<' '<<i<<endl;
					cnt++;
				}
			}if(cnt!=m){
				return;
			}else{
				maxy=max(maxy,ans);
				//cout<<endl<<"----------------"<<endl;
			}
		}
		return;
	}
	if(sum>0){
		book[x]=1;
		dfs(x+1,sum-1);
	}else{
		dfs(x+1,sum);
	}
	book[x]=0;
	dfs(x+1,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	modyo=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		modyo=modyo&a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20&&m<=20){
		dfs(0,m);
	}else if(m==1){
		cout<<maxn;
		return 0;
	}else if(m==n){
		cout<<modyo;
		return 0;
	}else if(m==2){
		dfs(0,m);
	}else if(m==n-1){
		int ans=a[1],sum=a[1];
		for(int i=1;i<=m;i++){
			ans=ans&a[i];
		}
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		maxy=max(ans,sum);
	}else{
		dfs(0,m);
	}
	cout<<maxy;
	return 0;
}
