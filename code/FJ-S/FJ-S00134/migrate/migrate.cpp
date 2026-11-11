#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		int cnt=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
			if(x[j]-x[j-1]>d){
				x[j]=0;
				n=j;
				break; 
			}
			//cout<<x[i]<<" ";
		}
		if(x[])
		for(int j=1;j<=n;j++){
			//cout<<x[j]<<" ";
			for(int k=j+1;k<=n;k++){
				//cout<<x[j]<<" "<<x[k]<<" ";
				if(x[k]-x[j]==2*d-1){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;	
} 
