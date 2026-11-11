#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+10;
int c,T,flag;
ll n,d,a[N],f[N],ans,sum;
void ask(ll dis,ll lazy,ll low){
	if(low>=d) return;
	if(dis==0){
		sum++;
		if(sum==2) flag=2;
		else if(sum>2) flag=0;
		return;
	}
	for(ll i=lazy;i<=d;i++){
		ll temp=d-i;
		if(dis-i<0) break;
		ask(dis-i,lazy,low+temp);
		if(flag==0) break;
	}
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		flag=1;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if((i>1 && a[i]-a[i-1]>d) || flag==0){
				f[i]=1;flag=0;
			}
		}
		if(n<=3){
			cout<<0<<endl;continue;
		}
		for(ll i=1;i<=n;i++){
			if(f[i]==1) break;
			for(ll j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				if(f[j]==1) break;
				flag=1;
				ll temp=(a[j]-a[i])%d;
				if(temp==0) continue;
				ask(a[j]-a[i],temp,0);
				if(flag==2) ans++;
				sum=0;
			}
		}
		cout<<ans<<endl;
		ans=0;sum=0;
		memset(a,0,sizeof(0));
		memset(f,0,sizeof(f));
	}
	return 0;
}
