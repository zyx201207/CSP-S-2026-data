#include<bits/stdc++.h>
using namespace std;
long long c,T,mn;
long long n,d,ans=0;
long long x[2000005],s[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=0;
		mn=1e9;
		cin>>n>>d;
		for(int t=1;t<=n;t++){
			cin>>x[t];
			s[t]=x[t]-x[t-1];
			mn=min(s[t],mn);
		}
		if(mn>=d){
			cout<<0<<endl;
			continue;
		}
		for(int t=1;t<n-1;t++){
			int site=lower_bound(x+1,x+1+n,x[t]+d+1)-x;
			if(site>n)break;
			int num=site-t;
			//cout<<site<<" ";
			if(num>=3){
				for(int i=t+1;i<site;i++){
					if(s[i]<s[i+1]&&x[i+1]-x[t]<d){
						num--;
					}
					if(x[site]-x[i]>d)num--;
				}
				if(num==3){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
