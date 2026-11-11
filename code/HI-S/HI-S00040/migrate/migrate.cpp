#include<bits/stdc++.h>
using namespace std;
int c,T;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			int j=lower_bound(a+1,a+1+n,d)-a-1;
			for(int k=j+1;k<=n&&a[k]-a[j]<=d;k++)cnt++;
		}
		cout<<cnt<<"\n";
		memset(a,0,sizeof(a));
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

