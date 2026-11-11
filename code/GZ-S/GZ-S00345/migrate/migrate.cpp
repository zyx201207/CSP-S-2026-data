//GZ-S00345 贵阳市南明区新世界学校 文希昊 
#include<bits/stdc++.h> 
using namespace std;

long long c,t,n,d,sum[200000],a[200000],ans;

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		ans=0;
		if(d==1||n<=3||d>=3){
			sum[i]=0;
		}else{
			for(int j=1;j<=n;j++){
				if(a[i]-a[i-1]>=d){
					ans++;
				}
			}
			sum[i]=n-3-ans;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<sum[i]<<endl;
	}
		
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
