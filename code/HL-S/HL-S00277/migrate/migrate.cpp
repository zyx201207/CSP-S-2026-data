#include<bits/stdc++.h>
using namespace std;
const int N =5411;
long long lu[N][N],a[N];
long long c,t,n,d,swi,ans;
long long cx(long long x,long long y,long long fhz){
	if(lu[x][y])return lu[x][y];
	for(int j=y-1;j>x;j--){
		if(lu[x][j]){
			
			if(swi==0){
				swi++;
				fhz=cx(j,y,fhz)+lu[x][j];
				if(j-1>x){
					long long fhz2,fhz3;
					fhz2=cx(j-1,y,fhz)+lu[x][j-1];
					if(fhz2==fhz&&fhz!=0){
						if(j-2==x){
							ans++;
						}else{
							fhz3=cx(j-2,y,fhz)+lu[x][j-2];
							if(fhz3!=fhz2)ans++;
						}
					}
				}
				return fhz;
			}else{
			
				fhz=cx(j,y,fhz)+lu[x][j];
				
				return fhz;
			}
		}
	}
	return 0;
}
int run(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ans =0;
	cin>>n>>d;
	memset(lu,0,sizeof(lu));
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				lu[i][j]=1;
			}
		}
	}
	
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			if(lu[i][j]==0){
				swi=0;
				lu[i][j]=cx(i,j,0);
			}
		}
	}
	
	
	cout<<ans<<endl;
	
	return 0;
}
int main(){
	cin>>c>>t;
	while(t--){
		run();
	}
	return 0;
}
