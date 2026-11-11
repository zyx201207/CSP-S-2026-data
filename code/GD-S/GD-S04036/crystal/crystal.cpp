#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+10;
LL n,m,ans,pl,pl1,pr,ans1,d;
vector<LL> a;
unordered_map<LL,LL>u;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(LL i=0,p;i<n;i++){
		scanf("%lld",&p);
		a.push_back(p);
	}
	sort(a.begin(),a.end());
	for(LL i=1;i<n;i++)
		if(a[i]==a[i-1]){
			ans1++;
			if((i-2>=0)&&(a[i]!=a[i-2]))pl1=i-1;
		}else{
			if(ans1>ans){
				ans=ans1;
				pl=pl1;
				pr=i;
			}
			ans1=1;
			u[i]=a[i]-a[i-1];
		}
	if(ans1>ans)ans=ans1;
	d=a[1]-a[0];
	long double c=0.5*(sqrt(d*d+8*m*d)-d)*(1.0/d);
	if(floor(c)>ans)ans=floor(c);
	printf("%lld",ans+1);
	return 0;
}
