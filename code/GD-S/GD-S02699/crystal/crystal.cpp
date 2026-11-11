#include<bits/stdc++.h>

using namespace std;
int n;
long long m;
long long a[5000005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		//if(a[i]!=i) f=1;
	}
	/*if(f==0){
		long long _m=m*2;
		cout<<ceil(sqrt(m));
		return 0;
	}*/
	sort(a+1,a+n+1);
	long long minn=-1e18;
	long long ans=0;
	int id=0;
	for(int i=2;i<=n;i++){
		ans=0;
		for(int j=i;j>=1;j--){
			//cout<<j<<' ';
			//if(i==3&&j==1) cout<<ans<<' '<<id<<'\n';
			if(a[i]-a[j]+ans<=m){
				
				ans+=a[i]-a[j];
				id=j;
				//if(i==3&&j==1) cout<<ans<<' '<<id;
				minn=max(minn,(long long)i-id+1);
				//cout<<ans<<' ';
			}
			else{
				//cout<<i<<' '<<id<<'\n';
				//cout<<minn<<' ';
				break;
			}
		}
	}
	cout<<minn<<'\n';
	return 0;
}
