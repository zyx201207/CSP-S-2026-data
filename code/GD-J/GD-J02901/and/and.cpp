#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int ans=-1;
void dfs(int x,int cnt,int sum){
	if(x>n){
		if(cnt>m){
			ans=max(ans,sum);
		}
		return;
	}
	if(cnt==1){
		dfs(x+1,cnt+1,a[x]);
		dfs(x+1,cnt,0);
	}else{
		dfs(x+1,cnt+1,sum&a[x]);
		dfs(x+1,cnt,sum);
	}
}
void S_small(){
	dfs(1,1,0);
	cout<<ans<<endl;
	return;
}
void S_m_n(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return;
}
void S_m_1(){
	for(int i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans<<endl;
	return;
}
int sum[N],sum1[N];
void S_m_n_1(){
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]&a[i];
	}
	sum1[n]=a[n];
	for(int i=n-1;i>=1;i--){
		sum1[i]=sum1[i+1]&a[i];
	}
	ans=max(sum[n-1],sum1[2]);
	for(int i=2;i<=n-1;i++){
		int x=sum[i-1]&sum[i+1];
		ans=max(x,ans);
	}
	//cout<<".";
	cout<<ans<<endl;
	return;
}
void S(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		S_m_1();
		return;
	}
	if(m==n){
		S_m_n();
		return;
	}
	if(m==n-1){
		S_m_n_1();
		return;
	}
	
	if(n<=20||1){
		S_small();
		return;
	}
	
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) S();
	return 0;
}

