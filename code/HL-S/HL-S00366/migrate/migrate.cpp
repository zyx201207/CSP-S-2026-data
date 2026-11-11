#include <bits/stdc++.h>
using namespace std; 
int c,t;
int n[500005],d[500005],x[500005][500005],i,way[500005][500005],count=0;
void way(int qi,int zho,int step,int s){
	for (int k=1;k<s;k++){
		for(int j=0;j<n[i];j++){
			if (qi==zhong){
				way[step]+1;
				return 0;
			}
				
			if (qi+i==x[i][j]){
				void way(qi+i,zho,step+1,s);
			}

		}
		
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n[i]>>d[i];
		for(int j=0;j<n[i];j++){
			cin>>x[i][j];
		}
	}
	if(c==0){	
		for(int i=0;i<t;i++){
			count=0;
			for(int j=0;j<n[i];j++){
				for(int k=j+1;k<n[i];k++){
					way(j,k,0,d[i]);
				}
			}
			for(int j=0;j<n[i];j++){
				if (way[step]>2)
					count++;
			}
			cout<<count;
		}
	}
}
