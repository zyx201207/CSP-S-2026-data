#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N];
int f[5010][5010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		unsigned long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			memset(f[i],0,sizeof(f[i]));
		}
		for(int i=1;i+3<=n;i++){
			for(int j=i+3;j<=n;j++){
				int old=i,now=i+1;
				int sum=0;
				while(now<=j){
					while(now<=j&&a[now]-a[old]<=d){
						now++;
					}
					if(now-1==old){
						break;
					}
					old=now-1;
					sum++;
				}
				f[i][j]=1;
				sum=1;
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
