#include<bits/stdc++.h>
using namespace std;

int c,t,n,d;
int dist[200005],a[200005],sum[200005];
int ru[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c>=11&&c<=12){
			if(d<2*(a[2]-a[1]+1)||n<2)
			cout<<0;
			else{
				cout<<n-2;
			}
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
	
			
	

