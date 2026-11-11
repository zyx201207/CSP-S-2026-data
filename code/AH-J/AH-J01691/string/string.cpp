#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,a[N],ans,l,r,llen,rlen;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	ans=0,l=1,r=n,llen=a[1],rlen=a[n];
	while(l<r){
		if(llen<rlen){
			if(c[l]!=c[r])ans+=llen;
			rlen-=llen;
			llen=a[++l];
		}
		else if(llen>rlen){
			if(c[l]!=c[r])ans+=rlen;
			llen-=rlen;
			rlen=a[--r];
		}
		else{
			if(c[l]!=c[r])ans+=llen;
			llen=a[++l],rlen=a[--r];
		}
	}
	cout<<ans<<endl;
	return 0;
}
