#include<bits/stdc++.h>
using namespace std;
long long c,m,a[500001],b[500001];
int ans=0,n;
int main(){
	//freopen("r","crystal.in",stdin);
	//freopen("w","crystal.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	//n=500001;m=1000000000000;for(int i=1;i<n;i++) a[i]=0;a[n]=1000000000000;
	for(int r=1;r<=n;r++){
		long long t=a[r]*(ans)-b[r]-b[r-ans-1];
		int t1=0;
		for(int l=r-ans;l>=1;l--){
			if(l!=r-ans) t+=a[r]-a[l];
			c++;
			//cout<<l<<' '<<r<<endl;
			if(t>m){
				break;
			}
			t1=r-l+1;
			ans=max(ans,t1);
			//cout<<"ans="<<ans<<endl;
			//cout<<"t1="<<t1<<endl;
		}
	}
	//cout<<c<<endl;
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	//long long a=1;a<<=63;
	//cout<<a;
	return 0;
}
