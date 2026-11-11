#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k,d;
long long u,v,m,h,ans;
int x[2000003];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in ","r",stdin);
	freopen("migrate.in ","r",stdin);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(c>=11&&c<=12){
			int cha=x[2]-x[1];
			int s=d/cha;
			if(s==1) cout<<0<<endl;
			else{
				int g=s-1;
				int ans=n-g;
				ans=ans*g;
				cout<<ans<<endl;
			}
		}else{
			int s=0;
			int l=1,r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(x[mid]==x[1]+d){
					s=mid;
					l=r+1;
				}else if(x[mid]<x[1]+d){
					s=mid;
					l=mid+1;
				}else{
					r=mid;
				}
			}
			h=n-s;
			ans=(h*(h+1))/2;
			cout<<ans<<endl;
		}
	}
	return 0;
}
