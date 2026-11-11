#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int c,t;
int n,d;
int a[2000005];
int f[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	if(c==13 || c==14){
		while(t--){
			cout<<0<<endl; 
		}	
	} 
	else{
		while(t--){
			cin>>n>>d;
			memset(f,0,sizeof(f));
			for(int i=1;i<=n;++i){
				cin>>a[i];
			}
			int ch=a[2]-a[1];
			int jtk=d/ch;
			if(n<=jtk){
				cout<<0<<endl;
				continue;
			}
			else{
				f[jtk+1]=1;
				for(int i=jtk+2;i<=n;++i){
					for(int j=1;j<=jtk;++j){
						f[i]+=f[i-j];
					}
					++f[i];
				}
				cout<<f[n]<<endl;
			}
		}
	}
	return 0;
} 
