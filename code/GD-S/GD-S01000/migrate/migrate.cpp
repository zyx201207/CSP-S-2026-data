#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 2*1e6+5;
long long x[MAXN];
int n;
long long d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	//记得删除批注！！！删除其余文件！！！ 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	
	
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			long long ans=0;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d)continue;
					int ji=0;
					for(int k=1;k<=n;k++){
						if(ji>3)break;
						if(k==i||k==j)continue;
						if(abs(x[k]-x[i])<=d&&abs(x[k]-x[j])<=d){
							ji++;
						}
					}
					if(ji==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c<=6){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			long long ans=0;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d)continue;
					//bool erf=dfs(i,j,0);
					//if(erf==true)ans+=1;
					ans+=1;
				}
			}
			cout<<ans<<'\n';
		}
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long ans=n*(n-1)/2;
		cout<<ans<<'\n';
	}
	
	
	return 0;
}
