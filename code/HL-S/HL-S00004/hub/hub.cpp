#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u,v,m,h,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>u>>v;
		}
		m=n/2;
		if(k>m){
			cout<<1<<endl;
		}else{
			h=m-k;
			if(h%2==0){
				ans=h/2+1;
			}else{
				ans=h/2+2;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
