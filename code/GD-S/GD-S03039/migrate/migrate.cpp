//csp RP++ !!!
#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000005],t,c;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t){
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d<=2){
			cout<<0<<endl;
			continue;
		}
		if(c==11||c==12){
			long long y=d/(x[n]-x[n-1]),a=x[n]-x[n-1];
			long long out=0;
			for(int i=1;i<y;i++){
				out+=(n/a-(y+i));
			}
			cout<<out<<endl;
		}
		else{
			long long ans=0;
			for(int i=2;i<=n;i++){
				for(int j=1;j<=(i+d/(x[i]-x[i-1]));j++){
					if(d/(x[i]-x[i-1])+j<n){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
		memset(x,0x3f3f3f,sizeof x);
	} 
	return 0;
}
