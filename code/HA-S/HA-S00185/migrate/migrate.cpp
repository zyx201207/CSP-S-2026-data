#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		long long a[n+1],ans=0;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		if(c==11||c==12){
			if(d<a[2]-a[1]){
				cout<<0;
				continue;
			}
			for(int j=1;j<=n;j++){
				for(int k=j+2;k<=n;k++){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
		else
		if(c==13||c==14){
			int sum=0;
			for(int j=1;j<n;j++){
				int l=1,r=n;
				while(1==1){
					int p=(l+r)/2;
					if(a[p]-a[j]<=d){
						l=i;
					}
					else{
						r=i;
					}
					if(l==r){
						sum+=n-l+1;
					}
				}
			}
			cout<<sum<<endl;
		}
		else{
			int h;
			if(h<0)
			h=0;
			cout<<h;
		}
	}
	return 0;
}
