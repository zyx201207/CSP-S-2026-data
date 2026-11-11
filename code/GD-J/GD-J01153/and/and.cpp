#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],mx,vis[N],ans=-1,cnt;
long long power[30];
void dfs(int t){
	if(t==0){
		mx=max(ans,mx);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			cnt=ans;
			ans&=a[i];
			dfs(t-1);
			ans=cnt;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=1,tu=1,v;
	power[0]=1;
	for(int i=1;i<=30;i++){
		power[i]=power[i-1]*2;
		if(n==power[i])v=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool f=1;
		for(int i=1;i<=30;i++){
			if(a[i]!=power[i]-1)f=0;
		}
		if(a[i]!=i-1)tu=0;
		if(!f)flag=0;
		mx=max(mx,a[i]);
	}
	if(flag){
		sort(a+1,a+1+n);
		cout<<a[m];
		
	}
	else if(tu&&v){
		cout<<mx-power[m-1]+1;
	}
	else if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==1){
		cout<<mx;
	}else if(m==2){
		mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(a[i]&a[j],mx);
			}
		}
		cout<<mx;
	}else{
		mx=0;
		dfs(m);
		cout<<mx;
	}
	return 0;
}

