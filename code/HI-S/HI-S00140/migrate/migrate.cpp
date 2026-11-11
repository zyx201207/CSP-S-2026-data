#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long r,t;
	cin>>r>>t;
	while(t--){
		long long n,l;
		cin>>n>>l;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ant=0;
		for(int i=1;i<n;i++){
			int j;
			for(j=i+2;j<=n&&a[j]-a[i]<l*2;j++){
				if(a[j]-a[i]>l){
					long long cnt=0;
					for(int k=i+1;k<j&&cnt<=2;k++){
						if(a[k]-a[i]<=l&&a[j]-a[k]<=l)
						{
							cnt++;
						}
					}
					if(cnt==2){
						ant++;
					}
				}
			}
		}
		cout<<ant<<"\n";
	}
	
	
	return 0;
}

