#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i_=1;i_<=t;i_++){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int len=a[2]-a[1];
		int jp=d/len;
		if(jp==1||jp==0){
			cout<<0<<'\n';
			continue;
		}
		for(int i=jp+1;i<n;i++){
			if(i%jp!=0)
				ans+=n-i;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
