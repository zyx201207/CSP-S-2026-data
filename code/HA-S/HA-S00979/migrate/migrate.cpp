#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			int sum;
			for(int k=j;k<=n;k++){
				if(a[k]>a[j]+d){
					sum=k;
				}
			}
			for(int k=sum;k<=n;k++){
				int sum1=-1;
				long long v=(a[sum]-a[j])%d;
				if(v!=0){
					int m=(a[sum]-a[j])/d;
					for(int f=j+1;f<=k;f++){
					    if(a[f]-a[f-1]<=d){
						    sum1++;
					    }
				    }
				    if(sum1-m==1){
				    	ans++;
				    }
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

