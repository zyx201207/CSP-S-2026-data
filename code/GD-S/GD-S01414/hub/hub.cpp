#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,ans,a,n,k,b;
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>a>>b;
			if(a==1){
				ans++;
			}
			if(b==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
