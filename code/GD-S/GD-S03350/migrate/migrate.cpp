#include<bits/stdc++.h>
using namespace std;
int _,q,n,d,a[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>_>>q;
	while(q--){
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=0;
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d&&a[j]-a[i]>d)cnt++;
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
