#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long c,t;
	cin>>c>>t;
	long long n,d;
	long long x;
	long long sum=0;
	long long c=0;
	long long a[1000000000]={0};
	long long b[1000000000]={0};
	long long d[1000000000]={0};
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		cin>>x;
		for(int j=1;j<=x;j++){
			sum=(d[j]+d[x])*x/2;
			cout<<sum<<endl;
			return 0;
		}
		if(t==1){
			cout<<"1"<<endl;
			return 0;
		}
		c++;
		if(a[i]+d*c==b[i]+d*c){
			sum++;
		}
	}
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
