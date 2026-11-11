#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int a,int b){
	return a>b;
}
long long a[200005],s[200005];
long long maxx,ans;
void dfs(int k,int id,long long sum){
	if(k==m+1){
		maxx=max(maxx,sum);
		return ;
	}if(id==n+1) return ;
	int num=sum&a[id];
	dfs(k+1,id+1,num);
	dfs(k,id+1,sum);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool B=1; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) B=0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(1,i,a[i]);
			ans=max(maxx,ans);
		}
		cout<<ans;
		return 0;
	}//1~5 25分 
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}// 6 5分 
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}// 7 5分 
	if(B){
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}//14 15 10分 
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}//8~10 15分 
	if(m==n-1){
		for(int i=1;i<=n;i++){
			maxx=a[1];
			for(int j=2;j<=n;j++){
				if(i==j)continue;
				maxx=maxx&a[j];
			}
			ans=max(ans,maxx);
		}
		cout<<ans;
		return 0;
	}
	else{
		sort(a+1,a+n+1,cmp); 
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	} //本题60分 
	return 0;
}
