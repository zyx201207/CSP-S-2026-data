#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long cnt=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i+1]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i]>d){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
