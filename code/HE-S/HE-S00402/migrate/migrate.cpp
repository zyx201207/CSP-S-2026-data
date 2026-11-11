#include<bits/stdc++.h>
using namespace std;
int n,c,t,d,x[2000005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(c==11 || c==12){
			int cha=x[2]-x[1];
			int mf=cha/d+1;
			if(mf==2) mf=3;
			for(int i=max(mf,3);i<=n-1;i++){
				ans+=n-i;
			}
			cout<<ans<<endl;
		}
		else if(c==13||c==14){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					int dd=x[j]-x[i];
					if(dd>d && !(n%2==1 && i==1 && j==n)) ans++;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
