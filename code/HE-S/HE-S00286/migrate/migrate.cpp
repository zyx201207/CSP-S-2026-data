#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	//cout<<c;
	for(int z=1;z<=t;z++){
		//x={0};
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			//cout<<"lzbgl";
		}
	
		int ans=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			int sum=0;
			for(int j=i+1;j<=n-1;j++){
				sum=sum+(x[j]-x[j-1]);
				if(sum>d){
					break;
				}
				cnt++;
				if(cnt>=2){
					if((x[j+1]-x[j])<=d){
						ans++;
					}
				}
				//cout<<sum<<cnt<<endl;
				
			}
			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}      
