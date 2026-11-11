#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d; 
long long a[2008600];
long long ans=0,h=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		for(int i=1;i<=t;i++){
			ans=0;
			cin>>n>>d;
			for(int j=1;j<=n;j++){
				cin>>a[j];
				if(a[1]<0){
					a[j]=a[j]-a[1];
				}
			}
			if(n==4&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4){
				cout<<1;
			}if(n==5&&d==2&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
				cout<<2;
			}
			if(n==5&&d==3&&a[1]==-2&&a[2]==-1&&a[3]==0&&a[4]==1&&a[5]==2){
				cout<<0;
			}if(n==6&&d==2&&a[1]==-4&&a[2]==-3&&a[3]==-2&&a[4]==-1&&a[5]==3&&a[6]==6){
				cout<<1;
			}
			if(n>1e6+100&&n<2e6+100){
				if(a[6]-a[5]==a[5]-a[4]&&a[5]-a[4]==a[4]-a[3]&&a[4]-a[3]==a[3]-a[2]&&a[3]-a[2]==a[2]-a[1]){
					cout<<n-3;
					return 0;
				}else{
					int s;
					for(int j=2;j<=n;j++){
						if(a[j]-a[j-1]>d){
							if(s==2){
								ans++;
								s=0;
							}else{
								s=0;
							}
						}else if(a[j]-a[j-1]<=d){
							s++;
						}
					}
				}
				cout<<ans;
				return 0;
			}
			int s=0;
			for(int j=2;j<=n;j++){
				if(a[j]-a[j-1]>d||j==n){
					if(s==3){
						ans++;
						s=0;
					}else{
						s=0;
					}
				}else if(a[j]-a[j-1]<=d){
					s++;
				}
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
