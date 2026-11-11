#include<bits/stdc++.h>
using namespace std;
long long x[100000001];
long long y[100000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long l,r,mid;
	long long ans=0;
	long long c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
	}
	sort(x+1,x+1+n);
	bool f=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(abs(x[i]-x[j]<=d)||y[i]+y[j]==n-1){
				f=1;
				ans++;
			}
			else{
				ans=0;
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans<<endl;
	}
	return 0;
}
