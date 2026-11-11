#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200010;
ll n,m,l[N],ss;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&l[i]);
	sort(l+1,l+n+1,greater<ll>());//ÅÅÐò 
	for(int i=29;i>=0;i--){//Ì° 
		ll s=0;
		for(int j=1;j<=n;j++){
			if((1<<i)&l[j])s++;
		}
		if(s>=m){
			ss|=(1<<i);
			for(int j=1;j<=n;j++){
				if(!((1<<i)&l[j]))l[j]=0;
			}
		}
	}
	printf("%lld",ss);
	return 0;
}
