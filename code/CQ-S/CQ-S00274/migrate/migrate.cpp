#include<bits/stdc++.h>
using namespace std;

long long arr[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>arr[i];
		}
		//µÈ²î
		long long d1=arr[2]-arr[1];
		//for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(d1>=d||d/d1==1){
					cout<<0<<endl;
					break;
				}
				else{
					if(n%2==0){
						long long ch=n-1;
						cout<<(ch-1)/d<<endl;
						break;
					}else{
						long long ch=n;
						cout<<(ch-1)/d<<endl;
						break;
					}
				}
			} 
		//}
	}
	return 0;
}
