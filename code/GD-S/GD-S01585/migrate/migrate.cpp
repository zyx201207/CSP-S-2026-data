#include<bits/stdc++.h>
using namespace std;
int c,t,x[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		memset(x,0,sizeof(0));
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int y=0;
		for(int i=1;i<=n;i++){
			int g=x[i]+d+1;
			for(int j=i;j<=n;j++){
				if(x[j]==g){
					if(j-i==3){
						y++;
					}
				}
			}
		}
		cout<<y<<endl;
	}
	return 0;
} 
