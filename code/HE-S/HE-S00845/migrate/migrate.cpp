#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000006],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j+=d){
				if(abs(a[j]-a[i])<=d)break;
				if(abs(a[j]-a[i])<=d*(j-1)){
					int m=0;
					for(int k=i+1;k<=j;k++){
						if(abs(a[k]-a[k-1])>d)break;
						else m++;
					}
					if(m==j-i)ans++;
				}
				else break;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
}
