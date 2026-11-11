#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[1000005],ans;
int main(){
	freopen("migrate6.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<n;i++)
			if(i+3<=n) 
				for(int j=i+3;j<=n;j++){
					if(a[j]-a[i]<=d||(a[j]-a[i])%d==0||a[i+1]-a[i]>d||a[i+2]-a[i]>d) break;
					else ans++;
}
		cout<<ans<<"\n";
	}
	return 0;
} 
