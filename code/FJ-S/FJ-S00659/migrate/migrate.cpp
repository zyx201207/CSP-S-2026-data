#include<bits/stdc++.h>
using namespace std;
long long a,b,c[2000007],d,e,ans,q,w;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>q>>w;
	while(w--){
		ans=0;
		cin>>a>>b;
		for(int x=1;x<=a;x++){
			cin>>c[x];
		}
		if(a==1 && b>=1){
			cout<<0<<"\n";
			continue;
		}else if(b==1){
			cout<<0<<"\n";
			continue;
		}
		for(int x=1;x<=a;x++){
			if(c[x+1]-c[x]<=b && c[x+2]-c[x]<=b && c[x+3]-c[x+2]<=b && c[x+3]-c[x]>b){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
