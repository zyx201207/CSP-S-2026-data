#include<bits/stdc++.h>
using namespace std;
int a[2000005],b[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int c=a[2]-a[1];
		d/=c;
		d++;
		for(int i=n;i>=n%2;i-=2){
			b[i]=i;
		}
		int ans=0;
		for(int i=d;i<n;i++)	ans+=b[i];
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
