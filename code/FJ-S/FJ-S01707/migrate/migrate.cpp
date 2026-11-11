#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,ans;
long long x_1,x,x1,x2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c==11 || c==12){
			cin>>x_1>>x>>x1;
			if(x-x_1<=d) {cout<<0;
				for(long long i=4;i<=n;i++) cin>>x2;
			continue;
			}
			if(x1-x_1<=d) {cout<<n-3;
				for(long long i=4;i<=n;i++) cin>>x2;
			continue;
			}
			else {cout<<0;
				for(long long i=4;i<=n;i++) cin>>x2;
			continue;}
		}
		if(c==13 || c==14){
			cin>>x>>x1>>x2;
			for(long long i=3;i<n;i++){
				x_1=x;x=x1;x1=x2;cin>>x2;
				if(x2-x_1>=d) ans++;
			/*	x_1=x;x=x1;x1=x2;x2=xC;cin>>xC;
				if(x-x_1==d) {if(x2-x<=d && xC-x1<=d) ans++;}
				else if(x1-x_1<=d) ans++;*/
			}
			cout<<ans;
		}
		
	}
}

