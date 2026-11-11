#include<bits/stdc++.h>
using namespace std;
long long int c,t,l,n,m,ans;
int b[2000010],a[2000010][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int pp=1;pp<=t;pp++){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>b[i];
		}
		for(int i=1;i<=n-3;i++){
			if(b[i+1]-b[i]<=m&&b[i+2]-b[i]<=m&&b[i+3]-b[i+2]<=m&&b[i+3]-b[i+1]<=m&&b[i+3]-b[i]>m){
				a[i][1]+=1;
					a[i+1][1]+=1;
						a[i+2][1]+=1;
							a[i+3][1]+=1;
			}
		}
		a[n+1][1]=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]==0){
				cout<<i;
				if(a[i+1][1]){
					a[i][1]+=4;	
				}
				if(a[i-1][1]){
					a[i][1]+=4;	
				}
			}
		}//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5 
		for(int i=1;i<=n;i++){
			ans+=a[i][1];
		}cout<<ans/4-l<<endl;l=ans/4;
	}
	
	return 0;
}
