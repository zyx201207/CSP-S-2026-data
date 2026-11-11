#include<bits/stdc++.h>
using namespace std;
int b[5000010];
long long n,d,j,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[0]<0) j=abs(a[0]);
			else if(a[i]>=0&&i==0) j=0;
			a[i]+=j;
			b[a[i]]=1;
		}
		long long ans=0;
		for(int i=0;i<n-1;i++){
			if(b[a[i]+2*d-1]==1&&a[i+1]<=a[i]+d){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
