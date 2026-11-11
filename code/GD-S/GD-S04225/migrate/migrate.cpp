#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
		
	//cout<<"4353456343453"<<endl;
	
	long long s,t;
	cin>>s>>t;
	cout<<s<<" "<<t;
	for(long long k=0;k<t;k++){
		long long n,d;
		cin>>n>>d;
		//cout<<n<<" "<<d;
		long long u[100000];
		for(long long i=0;i<n;i++){
			cin>>u[i];
		}
		long long g=0;
		//cout<<g;
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
				long long f=u[j]-u[i];
				if(f>d){
					for(long long v=2;v<(j-i);v++){
						if(f>(n-1)*d&&f<n*d){
							g+=1;
						}
					}
				}
			}
		}
		cout<<g;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
