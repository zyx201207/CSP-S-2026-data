#include<bits/stdc++.h>

using namespace std;
int m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1&&n<=2000){
		int mx=-1;
		for(int i=1;i<=n;i++){
			int aa;
			cin>>aa;
			mx=max(aa,mx);
		}
		cout<<mx;
		return 0;
	}
	if(m==n&&n<=2000){
		int ans;
		cin>>ans;
		for(int i=2;i<=n;i++){
			int aa;
			cin>>aa;
			ans=ans&aa;
		}
		cout<<ans;
		return 0;
	}
	if(m==2&&n<=2000){
		int a[2005];
		memset(a,0,sizeof(a)); 
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					mx=max(mx,a[i]&a[j]);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	return 0;
}
