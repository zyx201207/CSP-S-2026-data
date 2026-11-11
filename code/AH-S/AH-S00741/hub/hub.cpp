#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C,t,n,m,x,y,a[1000001],T,ans,c;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		memset(a,0,sizeof(a));t=1,c=0;
		for(int i=1;i<n;i++){cin>>x>>y;a[i]=abs(x-y);}
		stable_sort(a+1,a+n);
		for(int i=2;i<n;i++)if(a[i]==a[i-1])t++;else{if(t>c)c=t,ans=a[i-1];t=1;}
		if(t>c)c=t,ans=a[n-1];
		cout<<ans<<'\n';
	}
	return 0;
}
