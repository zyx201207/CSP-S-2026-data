#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long s[1000005];
int main(){
	freopen("migrate3.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t,n,d,sum=0;
	cin>>c>>t;
	for(long long i=1;i<=t;i++){
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>a[i];
		}
		int p=n;
		for(long long j=2;j<=p;j++){
			s[j]=s[j]+a[j]-a[j-1];
			if(s[j]<=d&&s[j+i]>d){
				memset(s,0,sizeof(s));
				sum++;
			}
		}
		cout<<sum<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
