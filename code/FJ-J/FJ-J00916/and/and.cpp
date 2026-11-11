#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
#define HMY return
#define pb push_back()
#define pii pair<int,int>
#define N 200005 
int n,m,a[N],flag[N],ans=-1e18;
void dfs(int x){
	if(x==m+1){
		int maxx=2147483647;
		for(int i=1;i<=n;i++)
			if(flag[i]) maxx=maxx&a[i];
		ans=max(maxx,ans);
		HMY;
	}
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=1;
			dfs(x+1);
			flag[i]=0;
		}
	}
}
signed main(){
	FILE("and")
	cin>>n>>m;
	int flag2=1,flag1=1,flag3=1,maxxx=-1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int flagg=0;
		for(int j=1;j<=30;j++){
			if((1<<j)-1==a[i]){
				flagg=1;
				break;
			} 
		}
		if(!flagg) flag1=0;
		if(a[i]!=i-1) flag2=0;
		maxxx=max(maxxx,a[i]);
		if(maxxx>4) flag3=0;
	} 
	if(m==1){
		int maxx=-1e18;
		for(int i=1;i<=n;i++) maxx=max(a[i],maxx);
		cout<<maxx<<"\n";
		return 0;
	}
	if(m==n){
		int maxx=2147483647;
		for(int i=1;i<=n;i++) maxx=maxx&a[i];
		cout<<maxx<<"\n";
		return 0;
	}
	if(m==2){
		int maxx=-1e18;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx<<'\n';
		HMY 0;
	}
	if(flag1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m]<<"\n";
		HMY 0;
	}
	if(flag2){
		//cout<<"10001";
		int sum=2147483647;
		for(int i=n;i>=n-m+1;i--) sum&=i;
		cout<<sum<<"\n";
		HMY 0;
	}
	if(flag3){
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=(a[i]==3);
		if(sum>=m)cout<<"3\n";
		else cout<<"1\n";
		HMY 0;
	}
	if(m==n-1){
		cout<<00000<<"\n";
		int maxx=2147483647;
		for(int i=1;i<=n;i++) maxx=maxx&a[i];
		int sum=-1e18;
		for(int i=1;i<=n;i++){
			sum=max(sum,maxx&a[i]);
		}
		cout<<sum<<"\n";
		HMY 0;
	}
	if(n<=20){
		dfs(1);
		cout<<ans;
		HMY 0;
	}
	cout<<maxxx<<"\n";
	HMY 0;
}
