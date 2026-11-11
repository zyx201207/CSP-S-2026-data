#include<bits/stdc++.h>
using namespace std;
long long arr[2000005];
long long lu[2000005];
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>arr[i];
			lu[i]=0;
		}
		long long cnt=0;
		for(int k=1;k<=n;++k){
			for(int j=k+1;j<=n&&arr[j]-arr[k]<=d;++j){
				lu[j]=0;
				for(int i=j+1;i<=n&&arr[i]-arr[j]<=d;++i){
					lu[i]++;
				}
			}
			for(int i=k+1;i<=n;++i){
				if(lu[i]==2){
					cnt++;
				}
			}
		}
		for(int i=1;i<=n;++i){
			arr[i]=0;
			lu[i]=0;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
