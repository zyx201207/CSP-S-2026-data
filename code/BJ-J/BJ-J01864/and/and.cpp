#include<bits/stdc++.h>
using namespace std;
long long n,m;
long a[200005],f[2778],ta=1;
int t=0,c[200005],ans;
void dfs(int x){
	if(t>m){
		return;
	}
	else if(x>n){
		int ans1=-2e9;
		for(int i=1;i<=n;i++){
			if(c[i]){
				if(ans1==-2e9){
					ans1=a[i];
				}
				ans1&=a[i];
			}
		}
		ans=max(ans,ans1);
	}
	else{
		c[x]=1;
		t++;
		dfs(x+1);
		c[x]=0;
		t--;
		dfs(x+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	f[0]=1;
	for(int i=1;i<=22;i++){
		f[i]=2*f[i-1];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int pforta=0;
		for(int j=0;j<=21;j++){
			if(a[i]==f[j]-1){
				pforta=1;
				break;
			}
		}
		ta=ta&&pforta;
	}
	if(ta){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	else if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>ans)ans=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==(n-1)){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
	//	cout<<"qwertyuiop";
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int apt=a[i];
				apt&=a[j];
				ans=max(ans,apt);
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		dfs(1);
		cout<<ans;
		return 0;
	}
}
