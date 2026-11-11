#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int cha,z;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			cha=x[2]-x[1];
			if(i>2&&x[i]-x[i-1]!=cha){
				f=1;
			}
		}
		if(f==0){
			z=d/cha;
			if(z<=1){
				cout<<0<<endl;
			}else {
				cout<<max(0,n-(2*z-1))<<endl;
			}
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(x[j]-x[i]<=m)continue;
					if((j-i)==1)continue;
				}
			}
		}
	}
	return 0;
}
