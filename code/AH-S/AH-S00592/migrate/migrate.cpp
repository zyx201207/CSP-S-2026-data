#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+10;

int c,t;
int n,d;
int x[N];

int stp[N];
int nus[N];
int sum[N];

signed main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	
	while(t--){
		cin>>n>>d;
		
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		int ans=0;
		//cout<<"----------------------===========================++++++++++++++++++++++++++\n";
		for(int i=1;i<=n-1;i++){
			//cout<<"\n\n\n"<<i<<"---------------------------------------\n";
			
			int l=i;
			memset(stp,0,sizeof(stp));
			memset(nus,0,sizeof(nus));
			memset(sum,0,sizeof(sum));
			stp[i]=1;//step miner
			nus[i]=1;//ways number
			sum[1]=1;//the sum of step ways number
			
			for(int j=i+1;j<=n;j++){
				//cout<<j<<' '<<l<<' '<<x[l]<<' '<<x[j]<<' '<<x[l]+d<<"++++++++++++++++++\n";
				while(x[l]+d<x[j]){
					//cout<<l<<' '<<stp[l]<<' '<<nus[l]<<' '<<sum[stp[l]]<<"******************\n";
					sum[stp[l]]-=nus[l];
					l++;
				}
				
				stp[j]=stp[l]+1;
				nus[j]=sum[stp[l]];
				sum[stp[l]+1]+=nus[j];
				
				//cout<<l<<' '<<stp[j]<<' '<<stp[l]<<' '<<nus[j]<<' '<<stp[l]+1<<':'<<sum[stp[l]+1]<<"//////////////////////\n\n";
				if(nus[j]==2)ans++;
			}
		}
		//cout<<"-------------"<<'\n';
		cout<<ans<<'\n';
	}
	
	return 0;
}

/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
