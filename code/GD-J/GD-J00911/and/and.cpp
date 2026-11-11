#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[222222];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	if(m==1){
		int mx=-1;
		while(n--){
			int xx;
			cin>>xx;
			mx=max(mx,xx);
		}
		cout<<mx;
	}
	else if(m==2){
		int ans=-1;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}
	else if(m==n){
		int l;
		cin>>l;
		while(n--){
			int xx;
			cin>>xx;
			l&=xx;
		}
		cout<<l;
	}
	else if(m==n-1){
		int l;
		cin>>l;int f=0;
		while(n--){
			int xx;
			cin>>xx;
			if(l&xx<=l&&!f){
				continue;
				f=1;
			}
			l&=xx;
		}
		cout<<l;
	}
	else{
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i++){
			ans&=a[i];
		}
		cout<<ans;
		
	}
	cout<<0;
}
