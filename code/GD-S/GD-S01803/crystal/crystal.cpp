#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll in(){
	ll a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) a=a*10+c-'0';
	return a*f;
}
ll n,m,ans=1;
ll a[500010],q[500010];
ll s,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=in();m=in();
	for(int i=1;i<=n;i++){
		a[i]=in();
	}
	sort(a+1,a+1+n);
	ll lev=0,cnt=1;
	s=1;
	for(int i=1;i<=n;i++){
		lev+=(i-s)*(a[i]-a[i-1]);
		while(s<=i){
			if(lev>m){
				lev-=(a[i]-a[s]);
				s++;
			}
			else break;
		}
		ans=max(ans,i-s+1);
	}
	cout<<ans;
	return 0;
} 
