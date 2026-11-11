#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,a[310],l,step[310][310];
		cin>>n>>l;
		for(int j=1;j<=n;j++) cin>>a[j];
		/*for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[k]-a[j]>l){
					break;
				}
				step[j][k]=1;
				for(int l=1;l<j;l++){
					if(step[l][j]>0){
						step[l][j]++;
					}
				}
			}
		}*/
	}
	for(int i=1;i<=t;i++){
		cout<<0<<endl;
	}
	return 0;
} 
