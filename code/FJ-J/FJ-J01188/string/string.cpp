#include<bits/stdc++.h>
#define ll long long
const int N=2e5+10;
using namespace std;
ll a[N],n;
char c[N];
int main(){
	cin>>n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll t=1,w=n,ans=0;
	while(t<w){
		ll in=min(a[t],a[w]);
		a[t]-=in;a[w]-=in;
		if(c[t]!=c[w])ans+=in;
		if(a[t]==0)t++;
		if(a[w]==0)w--;
	}
	cout<<ans;
	return 0;
} 
