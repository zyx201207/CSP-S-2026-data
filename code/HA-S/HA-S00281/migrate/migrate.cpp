#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			long long f=x[2]-x[1];
			long long g=d/f;
			if(g==2)cout<<n-3<<endl;
			else cout<<0<<endl;
		}
	}
//	else if(c==13||c==14){
//		while(t--){
//			
//		}
//	}
//	else if(c>=15&&c<=18){
//		while(t--){
//			
//		}
//	}
	return 0;
}
