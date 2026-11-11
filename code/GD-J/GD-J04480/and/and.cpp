#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxn;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout,tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++) 
					if(i!=j&&j!=k&&i!=k) maxn=max(maxn,a[i]&a[j]&a[k]);
			}
		}
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++) 
					for(int x=1;x<=n;x++)
						if(i!=j&&i!=k&&i!=x&&j!=k&&j!=x&&k!=x) maxn=max(maxn,a[i]&a[j]&a[k]&a[x]);
			}
		}
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++) 
					for(int x=1;x<=n;x++)
						for(int y=1;y<=n;y++)
							if(i!=j&&i!=k&&i!=x&&i!=y&&j!=k&&j!=x&&j!=y&&k!=x&&k!=y) 
								maxn=max(maxn,a[i]&a[j]&a[k]&a[x]&a[y]);
			}
		}
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++) 
					for(int x=1;x<=n;x++)
						for(int y=1;y<=n;y++)
							for(int z=1;z<=n;z++)
								if(i!=j&&i!=k&&i!=x&&i!=y&i!=z&&j!=k&&j!=x&&j!=y&&j!=z
								&&k!=x&&k!=y&&k!=z)
									maxn=max(maxn,a[i]&a[j]&a[k]&a[x]&a[y]&a[z]);
			}
		}
	}
	cout<<maxn;
	return 0;
}
