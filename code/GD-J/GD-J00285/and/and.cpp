#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N],n,m,maxx=-1,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		maxx=a[n];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			maxx=maxx&a[i];
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=a[i]&a[j];
				maxx=max(ans,maxx);
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=a[i]&a[j];
				for(int k=j+1;k<=n;k++){
					ans=ans&a[k];
					maxx=max(ans,maxx);
				}
			}
		}
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=a[i]&a[j];
				for(int k=j+1;k<=n;k++){
					ans=ans&a[k];
					for(int o=k+1;o<=n;o++){
						ans=ans&a[o];
						maxx=max(ans,maxx);
					}
				}
			}
		}
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=a[i]&a[j];
				for(int k=j+1;k<=n;k++){
					ans=ans&a[k];
					for(int o=k+1;o<=n;o++){
						ans=ans&a[o];
						for(int h=o+1;h<=n;h++){
							ans=ans&a[h];
						}
					}
				}
			}
		}
	}
	cout<<maxx;
	return 0;
} 

