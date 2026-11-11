#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			mx=max(mx,t);
		}
		cout<<mx;
		return 0;
	}
	if(n==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(n==2){
			int a,b;
			cin>>a>>b;
			if(a==b){
				cout<<a;
				return 0;
			}else{
				cout<<(a&&b);
			}
		}else{
			int a[n+1];
			int t=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
				t=t&&a[i];
			}
			cout<<t;
		}
		return 0;
	}
	if(m==n){
		int u;
		cin>>u;
		int t=u;
		for(int i=2;i<=n;i++){
			cin>>u;
			t=t&&u;
		}
		cout<<t;
		return 0;
	}
	
	return 0;
}

