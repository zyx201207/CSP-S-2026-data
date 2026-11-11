#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000020];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(long long i=2;i<=n;i++){
			for(long long j=1;j<i;j++){
				long long sum=(x[i]-x[j])/d;
				if((x[i]-x[j])%d==0){
				}
				else sum++;//zuiduan
				if(sum==1)break;
				long long s,num=0,K;
				long long z[220];
				for(long long A=d;A>=d-1;A--){
					s=j,K;
					for(long long k=j+1;k<=i;k++){
						if(x[k]-x[s]+1>A){
							s=k;
							num++;
						}
						K=k;
					}
					if(x[K]-x[s]+1<=A){
						num++;
					}
					if(A==d&&num==2)break;
					else num=0;
				}
				if(num==2){
					//zaiyanzheng
//					bool flag=true;
//					for(int k=1;k<d;k++){
//						if((x[i]-x[j]+1)%k==0&&)flag=false;
//					}
//					if((x[i]-x[j]+1)/N<d){}
				 		//cout<<"x:"<<j<<" y:"<<i<<endl;
						ans++;
				 		
					}
				
					
			}
//				if(n==5&&d==2&&j==2&&i==5){
//					cout<<ans<<" "<<"x:"<<s<<" y:"<<K<<" ";
//					
//				}
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
