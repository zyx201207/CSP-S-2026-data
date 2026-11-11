#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[2000001],ans=0;
bool B[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(int i=1;i<=n-3;i++){
			for(int j=1;j<=2;j++){
				//cout<<a[i+j]-a[i]<<"  "<<a[i+3]-a[i+j]<<"\n";
				if(a[i+j]-a[i]>d || a[i+3]-a[i+j]>d){
					break;
				}
				if(j==2 && a[i+3]-a[i]>d){
					B[i]=1;
				}
			}
		}
		int t=0,lx=1,l=0;
		for(int i=1;i<=n;i++){
			//cout<<B[i]<<" ";
			if(B[i]){
				for(int j=i+1;j<=n;j++){
					if(B[j]){
						ans+=j-i;
						break;
					}else if(j==n || a[j+1]-a[j]>d){
						ans+=max(0,j-i-2);
						break;
					}
				}
			}
			//cout<<ans<<"     ";
		}
		cout<<ans<<"\n";
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/
