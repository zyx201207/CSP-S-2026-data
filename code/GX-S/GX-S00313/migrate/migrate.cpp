#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,ccb,max,cnt,min,cnt1=0;
	int a[9999],dp[9999]={0},m[9999],temp[9999];
	cin>>c>>t;
	for(int v=1;v<=t;v++){
		max=-9999999;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=2;i<=n;i++){
			m[i]=a[i]-a[i-1];
		}
		for(int i=2;i<=n;i++){
			ccb=0;
			min=-99999;
			for(int j=i;j>=2;j--){
				ccb+=m[j];
				if(ccb<=d && m[j]>min){
					min=ccb;
					dp[i]++;
				}
				else{
					break;
				}
			}
		}
		cnt=0;
		for(int i=2;i<=n;i++){
			if(dp[i]==2){
				cnt++;
			}
		}
		temp[cnt1]=cnt;
		cnt1++;
	}
	for(int i=0;i<cnt1;i++){
		cout<<temp[i]<<endl;
	}
	return 0;
}

