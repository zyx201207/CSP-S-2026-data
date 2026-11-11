#include<bits/stdc++.h>
using namespace std;
const int N=7e5+100;
int y,c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		y=0;
		for(int j=1;j<=n;j++){
			cin>>x[i];
			for(int c=x[1];c<n-d;c++){
				while(d){
					c+=d;
					d--;
					if(d==0){
					y++;
					}
				}
			} 
		}
	cout<<y<<endl;	
	}		
	return 0;		
}	

