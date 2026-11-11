#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200010];
long long ans=-1e18;

bool cmp(int x,int y){
	return x>y;
}


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	else if(n<=300&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(n<=60&&m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
				    ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans;
	}
	else if(n<=30&&m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
				        ans=max(ans,a[i]&a[j]&a[k]&a[l]);
				    }
				}
			}
		}
		cout<<ans;
	}
	else if(n<=15&&m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
				            ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]);
				        }
				    }
				}
			}
		}
		cout<<ans;
	}
	else if(n<=10&&m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int len=r+1;len<=n;len++){
				                ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[len]);
				            }
				        }
				    }
				}
			}
		}
		cout<<ans;
	}
	else if(n<=9&&m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int r=l+1;r<=n;r++){
							for(int len=r+1;len<=n;len++){
								for(int fu=len+1;fu<=n;fu++){
				                    ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[r]&a[len]&a[fu]);
				                }
				            }
				        }
				    }
				}
			}
		}
		cout<<ans;
	}
	else{
	    sort(a+1,a+n+1,cmp);
	    ans=a[1];
	    for(int i=2;i<=m;i++){
	    	ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
