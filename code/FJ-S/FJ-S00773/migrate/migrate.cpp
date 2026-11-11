#include<bits/stdc++.h>
using namespace std; 
long long c,t,n,d,a[3000006],x,cnt[100005],w;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		x=a[2]-a[1];
		cnt[w++]=n-d/x+1;
	}
	for(int i=0;i<w;i++)cout<<cnt[i]/2<<endl;
	return 0;
}
