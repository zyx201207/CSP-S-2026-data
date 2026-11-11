#include<iostream>
#include<cstdio>
using namespace std;
long long num[2000005];
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    cin>>c;
    long long t;
    cin>>t;
    for(int a=0;a<t;a++){
    	long long n,d;
    	cin>>n>>d;
    	for(long long i=0;i<n;i++){
    		cin>>num[i];
		}
		for(long long i=1;i<n;i++){
			num[i]=num[i]-num[0];
		}
		num[0]=0;
		long long ans=0;
		for(long long i=0;i<n;i++){
			for(long long j=i+1;j<n;j++){
				if(num[j]+num[i]==d*2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
