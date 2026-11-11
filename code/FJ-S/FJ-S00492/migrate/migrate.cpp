#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[100005],ans=0;
long long f(long long a,long long b){
	long long z=0;
	for(int y=b-a;y>=2;y--){
		z=0;
		for(int q=a;q<=b;q++){
			if(q+y>b){
				break;
			}
			if(d>=x[q+y]-x[q]){
				z++;
		 	}
		}
		if(z==2){
			break;
		}else if(z>0){
			break;
		}
	}
	if(z==2){
		return 1;
	}
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=1;j<n-2;j++){
			for(int p=j+3;p<=n;p++){
				ans+=f(j,p);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
