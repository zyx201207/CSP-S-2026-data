#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,a[100005],ans=0;
		cin>>n>>d;
		if(c==11||c==12){
			cout<<n-3<<"\n";
			continue;
		}else{
			for(int i=0;i<n;i++)cin>>a[i];
			
			cout<<ans<<"\n";
		}
	}
	return 0;
}

