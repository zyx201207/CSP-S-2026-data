#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct o{
	int x;
	char y;
}a[200005];
char b[200005];
int oo,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	std::ios::sync_with_std(false);
//	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		oo+=a[i].x;
	}
	if(oo<1e5){
		int u=1,k=0;
		for(int i=1;i<=oo;i++){
		
			if(i<=a[u].x+k&&i>=k+1){
				b[i]=a[u].y;
			}
			else{
				u++;
				k+=a[u-1].x;
				b[i]=a[u].y;
			}
			//cout<<k<<" "<<u<<endl;
		}
	
		for(int i=1;i<=oo/2;i++){
			int j=oo-i+1;
		//	cout<<j<<endl;
			if(b[i]!=b[j]){
				b[j]=b[i];
				ans++;
			}
		}
//			for(int i=1;i<=oo;i++){
//			cout<<b[i];
//		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i].y!=a[n-i+1].y){
				if(a[i].x>a[n-i+1].x){
					oo=0;
					for(int j=n-i+1;j>=1;j--){
						oo+=a[j].x;
						ans=oo;
						if(a[j].y==a[i].y){
							ans-=a[j].x;
							if(a[i].x<=oo){
								break;
							}
							else{
								continue;
							}
						}
						else if(a[i].x>=oo){
							a[j].y=a[i].y;
						}
						else{
							a[j+1].x+=(a[i].x-(oo-a[j].x));
							a[j].x-=(a[i].x-(oo-a[j].x));
							ans=ans-a[j].x+(a[i].x-(oo-a[j].x));
							break;
						}
							
					}
				}
				else{
					if(a[i].x==a[n-i+1].x){
						a[n-i+1].y=a[i].y;
						ans+=a[i].x;
					}
					else{
						if(n-i+1==n){
							a[n-i+1].x-=a[i].x;
							
							n++;
							a[n].y=a[i].y;
							a[n].x=a[i].x;
							ans+=a[i].x;
						}
						else{
							
							for(int j=n+1;j<=n-i+3;j--){
								a[j].x=a[j-1].x;
								a[j].y=a[j-1].y;
								
							}
							
							a[n-i+2].x=a[i].x;
							a[n-i+2].y=a[i].y;
							a[n-i+1].x-=a[i].x;
							ans+=a[i].x;
						}
						
					}
				}
			}
			
		}
	}
	
	cout<<ans;
	return 0;
}
