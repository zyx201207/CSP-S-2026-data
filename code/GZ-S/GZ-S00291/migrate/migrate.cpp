//GZ-S00291 张瑞晨 清华中学  
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010],cnt;
int x(long long b){
	for(long long i=1;i<=n;i++)if(a[i]==b)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout)； 
	cin>>c>>t;
	for(long long z=1;z<=t;z++){
		cin>>n>>d;
		for(long long i=1;i<=n;i++)cin>>a[i];
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				if(a[j]-a[i]==d+d-1&&x(a[i]+d)){
					cout<<a[i]<<" "<<a[j]<<endl;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
