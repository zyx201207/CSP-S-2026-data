#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	int ans=0;
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" "<<b[i]<<endl;
//	}
	while(l<r){
		if(b[l]!=b[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]>a[r]){
			 	if(a[r-1]>=a[l]-a[r]){
				 	if(b[r-1]!=b[l]){
						ans+=a[l]-a[r];		
					}
					if(a[r-1]==a[l]-a[r]){
						r-=2;
						l++;
					}else{
						a[r-1]-=a[l]-a[r];
						r--;
						l++;
					}			 		
				}
				else{
					int x=a[l]-a[r];
					int y=r-1;
					while(x>0){
						if(a[y]>x){
							if(b[y]!=b[l]){
								ans+=x;
							}
							a[y]-=x;
							x=0;
						}
						else if(a[y]==x){
							if(b[y]!=b[l]){
								ans+=x;
							}
							x=0;
							y--;
						}
						else{
							x-=a[y];
							if(b[y]!=b[l]){
								ans+=a[y];
							}
							y--;
						}
					}
					r=y;
					l++;
				}
			}//////////////////////////////////////////////////////////////////////
		else if(a[l]<a[r]){
			if(a[l+1]>=a[r]-a[l]){
			 	if(b[l+1]!=b[r]){
					ans+=a[r]-a[l];		
				}
				if(a[l+1]==a[r]-a[l]){
					r--;
					l+=2;
				}else{
					a[l+1]-=a[r]-a[l];
					r--;
					l++;
				}
			 		
			}else{
				int x=a[r]-a[l];
				int y=l+1;
				while(x>0){
					if(a[y]>x){
						if(b[y]!=b[r]){
							ans+=x;
						}
						a[y]-=x;
						x=0;
					}
					else if(a[y]==x){
						if(b[y]!=b[r]){
							ans+=x;
						}
						y++;
					}
					else{
						x-=a[y];
						if(b[y]!=b[r]){
							ans+=a[y];
						}
						y++;
					}
				}
				r--;
				l=y;
				}
		}
		else{
			l++;
			r--;
		}
	}
	cout<<ans<<endl;
} 
