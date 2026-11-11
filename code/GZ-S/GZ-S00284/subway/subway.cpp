//GZ-S00284 ¿Ó∫∆”Ó
#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int dit[n][m]={0};
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int sub[n][m];
	for(int i=0;i<n;i++){
		int jjh;
		cin>>jjh;
		for(int j=0;j<jjh;j++){
			int bc,t;
			cin>>bc>>t;
			sub[i][bc]=t;
			dit[i][bc]=1;
			bc++;
		}
	}
	for(int my=0;my<q;my++){
		int st,en,st1=-1,en1=-1;
		cin>>st>>en;
		int ans=w[st-1]+w[en-1];
		for(int i=0;i<n;i++){
			if(dit[i][st]==1 and st1==-1){
				st1=i;
			}
			if(dit[i][en]==1 and en1==-1){
				en1=i;
			}
			if(en1!=-1 and st1!=-1){
				break;
			}
		} 
		if(en1==st1){
			ans+=sub[st1][st]+sub[en1][en];
		}
		else{
			for(int i=0;i<m;i++){
				if(dit[st1][i]+dit[en1][i]==2){
					ans+=sub[st1][st]+sub[st1][i]+sub[en1][i]+sub[en1][en];
					break;
				}
				else if(i==m-1){
					i=0;
					int ks=st1,gc=st1+1;
					for(int j=st1;j<en1;j++){
						for(int z=0;z<m;z++){
							if(dit[ks][z]+dit[gc][z]==2){
								ans+=sub[ks][z]+sub[gc][z];
								ks=gc;
								gc++;
								z=0;
							}
							if(ks==en1){
								ans+=sub[gc][z]+sub[en1][en];
								break;
							}
						}
						gc++;
					}
				}
			}
		}	
		cout<<ans<<endl;	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
