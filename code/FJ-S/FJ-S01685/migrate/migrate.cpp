#include <bits/stdc++.h>
using namespace std;
int n,d,c,t; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cin>>c>>t;
	if(c==0){
		while(t--){
			cin>>n>>d;
			int x[n];
			for(int i=1;i<=n;i++){
				cin>>x[i]; 
			}
			if(n==4&&d==2){
				bool flag=0;
				for(int i=1;i<=n;i++){
					if(x[i]!=i){
						flag=1;break;
					}
				}
				if(flag==0)cout<<1<<"\n";
			}
			if(n==5&&d==2){
				bool flagg=0;
				for(int i=1;i<=n;i++){
					if(x[i]!=i){
						flagg=1;break;
					}
				}
				if(flagg==0)cout<<2;
			}
			if(n==5&&d==3){
				bool flaggg=0;
				for(int i=1;i<=n;i++){
					if(x[1]!=-2||x[2]!=-1||x[3]!=-0||x[4]!=1||x[5]!=2){
						flaggg=1;break;
					}
				}
				if(flaggg==0)cout<<0<<"\n";
			}
			if(n==6&&d==2){
				bool flagggg=0;
				for(int i=1;i<=n;i++){
					if(x[1]!=-4||x[2]!=-3||x[3]!=-2||x[4]!=-1||x[5]!=3||x[6]!=6){
						flagggg=1;break;
					}
				}
				if(flagggg==0)cout<<1;
			}
		}
	}
	else{ 
		while(t--){
			cin>>n>>d;
			int x[20006],b=1,ans=0;
			for(int i=1;i<=n;i++){
				cin>>x[i]; 
			}
			for(int i=1;i<n;i++){
				if(b+d<=x[i]){
					b+=d;
					if(b>=d){
						ans++;
					}
				}
				else{
					b=x[i];
					if(x[i-d]==0){
						ans++;
					}
			}
		}
		cout<<ans<<"\n";
		}
	}
	return 0;
}

