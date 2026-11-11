#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200001],s,t,x,y,ans,k,d,m;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i]>>c[i];d+=a[i];}
	x=1,y=n;
	while(k<d/2){
		m=min(a[x]-s,a[y]-t);
		if(m==a[x]-s)k+=a[x],x++,t=t+a[x-1]-s,s=0;else y--,s=s+a[y+1]-t,t=0;
		if(c[x]!=c[y])ans+=m;
	}
	cout<<ans;
	return 0;
}
