#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,m=0;
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	int x[200005]={0};
	for(int k=0;k<t;k++){
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(n==2){
			cout<<1<<endl;
			m=1;
		}else{
			if(n==d){
				cout<<0<<endl;
				m=1;
			}
			else{
				int j[n+1]={0},f=0,min=0,minn=917878,z=0;
				for(int i=0;i<n;i++){
					j[i]=abs(x[i+2]-x[i]);
					if(j[i]<=d){
						if(n%j[i]==0){
							min=n/j[i];
						}
						else{
							min=(n/j[i])+1;
						}
						if(min==minn){
							f+=1;
						}
						if(min<minn){
							minn=min;
						}
					}
					else{
						z+=1;
					}
					
				}
				if(!f){
					cout<<0<<endl;
				}
				else{
					cout<<f<<endl;
				}
			}
		}
	}
	
	
	return 0;
} 
