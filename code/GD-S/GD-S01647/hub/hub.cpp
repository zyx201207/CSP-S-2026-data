#include<bits/stdc++.h>
using namespace std;

int c,t,n,m,k,ans;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		m=n/2;
		if(k>=n)ans=0;
		else if(k>=m)ans=1;
		else{
			ans=(m-k+3)/4+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
