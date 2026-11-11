#include<bits/stdc++.h>
using namespace std;
long long x[1919810];
int main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long sum=0;
		for(long long i=1;i<=n-1;i++){
			for(long long j=i;j<=n;j++){
				if(abs(x[j]-x[i])==d+1){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
