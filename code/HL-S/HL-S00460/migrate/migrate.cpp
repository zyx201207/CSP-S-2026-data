#include<bits/stdc++.h>
using namespace std;
int p[10];
int q[10];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>p[i];
		}
		if(n==1){
			cout<<0;
			cout<<endl;
		}else if(n==2){
			cout<<0;
			cout<<endl;
		}else if(n==3){
			cout<<0;
			cout<<endl;
		}else if(n==4){
			if(p[3]-p[1]<=d&&p[4]-p[2]<=d&&p[4]-p[1]>d){
				cout<<endl;
			}else cout<<0;
			cout<<endl;
		}else if(n==5){
			//for(int i=1;i<n;i++){
			//	q[i]=p[i+1]-p[i];
			//}
			int ans=0;
			if(p[3]-p[1]<=d&&p[4]-p[2]<=d&&p[4]-p[1]>d){
				ans++;
			}
			if(p[4]-p[2]<=d&&p[5]-p[3]<=d&&p[5]-p[2]>d){
				ans++;
			}
			int tel=0;
			if(p[5]-p[4]<=d&&p[4]-p[1]<=d&&p[5]-p[1]>d){
				tel++;
			}
			if(p[5]-p[3]<=d&&p[3]-p[1]<=d&&p[5]-p[1]>d){
				tel++;
			}
			if(p[5]-p[2]<=d&&p[2]-p[1]<=d&&p[5]-p[1]>d){
				tel++;
			}
			if(tel==2){
				ans++;
			}
			if(tel==0){
				if(p[5]-p[4]<=d&&p[4]-p[2]<=d&&p[2]-p[1]<=d&&p[4]-p[1]>d){
					tel++;
				}
				if(p[5]-p[4]<=d&&p[4]-p[3]<=d&&p[3]-p[1]<=d&&p[4]-p[1]>d){
					tel++;
				}
				if(p[5]-p[3]<=d&&p[3]-p[2]<=d&&p[2]-p[1]<=d&&p[4]-p[1]>d){
					tel++;
				}
				if(tel==2){
					ans++;
				}
			}
			cout<<ans;
			cout<<endl;
		}else if(n==6){
			int tel=0;
			int ans=0;
			if(p[5]-p[4]<=d&&p[4]-p[1]<=d&&p[5]-p[1]>d){
				tel++;
			}
			if(p[5]-p[3]<=d&&p[3]-p[1]<=d&&p[5]-p[1]>d){
				tel++;
			}
			if(p[5]-p[2]<=d&&p[2]-p[1]<=d&&p[5]-p[1]>d){
				tel++;
			}
			if(tel==2){
				ans++;
			}
			if(tel==0){
				if(p[5]-p[4]<=d&&p[4]-p[2]<=d&&p[2]-p[1]<=d&&p[4]-p[1]>d){
					tel++;
				}
				if(p[5]-p[4]<=d&&p[4]-p[3]<=d&&p[3]-p[1]<=d&&p[4]-p[1]>d){
					tel++;
				}
				if(p[5]-p[3]<=d&&p[3]-p[2]<=d&&p[2]-p[1]<=d&&p[4]-p[1]>d){
					tel++;
				}
				if(tel==2){
					ans++;
				}
			}
			int mun=0;
			if(p[6]-p[2]<=d&&p[2]-p[1]<=d&&p[6]-p[1]>d){
				mun++;
			}
			if(p[6]-p[3]<=d&&p[3]-p[1]<=d&&p[6]-p[1]>d){
				mun++;
			}
			if(p[6]-p[4]<=d&&p[4]-p[1]<=d&&p[6]-p[1]>d){
				mun++;
			}
			if(p[6]-p[5]<=d&&p[5]-p[1]<=d&&p[6]-p[1]>d){
				mun++;
			}
			if(mun==2){
				ans++;
			}
			if(ans==0){
				if(p[6]-p[3]<=d&&p[6]-p[1]>d&&p[5]-p[1]>d){
					mun++;
				}
				if(p[6]-p[4]<=d&&p[4]-p[2]<=d&&p[6]-p[1]>d&&p[5]-p[1]>d){
					mun++;
				}
				if(p[5]-p[2]<=d&&p[6]-p[1]>d&&p[5]-p[1]>d){
					mun++;
				}
				if(p[6]-p[4]<=d&&p[3]-p[1]<=d&&p[6]-p[1]>d&&p[5]-p[1]>d){
					mun++;
				}
				if(p[5]-p[3]<=d&&p[3]-p[1]<=d&&p[6]-p[1]>d&&p[5]-p[1]>d){
					mun++;
				}
				if(p[4]-p[1]<=d&&p[6]-p[1]>d&&p[5]-p[1]>d){
					mun++;
				}
				if(mun==2){
					ans++;
				}
			}
			if(mun==0){
				if(p[6]-p[4]<=d&&p[4]-p[1]>d){
					mun++;
				}
				if(p[5]-p[3]<=d&&p[4]-p[1]>d){
					mun++;
				}
				if(p[4]-p[2]<=d&&p[4]-p[1]>d){
					mun++;
				}
				if(p[3]-p[1]<=d&&p[4]-p[1]>d){
					mun++;
				}
				if(mun==2){
					ans++;
				}
			}
			cout<<ans;
			cout<<endl;
		}
		
	}
	
	return 0;
}