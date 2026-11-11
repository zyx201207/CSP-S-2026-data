//GZ-J00403 ∂≠≤©”Ó 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool f[200010];
int ans;//

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int v=a[i]&a[j];
				ans=max(ans,v);
				cout<<ans;
			}
		}
	}
	return 0;
}


