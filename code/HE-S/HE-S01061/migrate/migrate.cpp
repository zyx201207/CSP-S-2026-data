#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	
	int c,t;
	cin >> c >> t;
	for(int e=0;e<t;e++){
		int ans=0;
		int n,d;
		cin >> n >> d;
		int x[n];
		for(int i=0;i<n;i++){
			cin >> x[i];
		}
		bool tu[n][n]={false}; 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(x[j]-x[i]<=d){
					tu[i][j]=true;
				}
			}
		}
		
		 
		for(int i=0;i<n;i++){
			int dds=0;
			for(int j=0;j<n;j++){
				if(tu[i][j]){
					dds++;
				}
				if(j-i>=3){
					int bs=0;
					int xyb[n]={i};
					int ci=0;
					bool ber=false;
					for(int l=0;l<n;l++){
						for(int k=0;k<n;k++){
							bs++;
							if(tu[xyb[i]][j]==1){
								ber=true;
								break;
							}
							if(tu[xyb[i]][k]==1){
								xyb[i]=k;
							}
						}
						if(ber){
							break;
						}
					} 
					if(dds=2 && bs>2){
						ans++;
					}
					
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
	}
