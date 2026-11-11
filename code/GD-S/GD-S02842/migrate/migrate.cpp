#include<bits/stdc++.h>
#define long long int 
using namespace std;
//手动测试 
int cs0=0;
int cs(int n,string s){
	if(cs0==0){
		cout<<s<<":"<<n<<endl;
	}
	return n;
}
//变量 
int c,t,n,d,all0=0;
int x[2000005],map0[2000005];
int dps2(int a,int b,int once){
	map0[a]=1;
	for(int i=n;i>=1;i--){
		if(abs(x[i]-x[a])<=d&&map0[i]==0){
			if(i==b){
				return once+1;
			}else{
				once+=dps2(i,b,once);
			}
		}
	}
	map0[a]=0;
	return once;
}
signed main(){
	if(cs0==0){
		ios::sync_with_stdio(0);
		cin.tie(0);
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	}
	//程序
	cin>>c>>t;
	for(int ii=1;ii<=t;ii++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int num=dps2(i,j,0);
				if(num==3){
					all0++;
					cs(i,"i");
					cs(j,"j");
					cs(num,"num");
				}
				
			}
			
		}
		cout<<all0<<endl;
	} 
	
	return 0;
} 
