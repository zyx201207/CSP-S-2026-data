#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	for(int ci=0;ci<t;ci++){
		int n,d;
		cin>>n>>d;
		int x[n];
		int howfar[n][n];
		int stop[n][n];
		for(int i=0;i<n;i++){
			for(int j=1;j<n;j++){
				int bushu=0;
				int far=0;
				for(int jump=i;jump<j;jump++){
					far+=x[jump]-x[i];
					if(far>d){
						if(bushu==0){
							stop[i][j]=jump--;
						}
						bushu++;
						jump--;
						far=0;
					}
				}
				howfar[i][j]=bushu;
			}
		}
		int shuliang=0;
		for(int i=0;i<=n;i++){
			for(int j=i+3;j<n;j++){
				for(int z=i+1;z<j;z++){
					if(howfar[z][j]+howfar[i][z]==howfar[i][j]&&stop[i][j]!=z)shuliang++;
				}
			}	
		}
		cout<<shuliang<<endl;
	}
	return 0; 
}
