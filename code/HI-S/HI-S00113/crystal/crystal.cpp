#include<bits/stdc++.h>
using namespace std;
int n;long long m,res;
long long maxn=-1000000000000,minn=10000000000000,flag1,flag2,sp;
long long a[500005],val[500005],p[500005];
double mxd;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(i==2) sp=a[i]-a[1];
		if(a[i]!=i) flag1=1;
		if(i>=2&&(a[i]-a[i-1]!=sp)) flag2=1;
	}
	if(!flag1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			p[i]=p[i-1]+i;
			if(m>=p[i]) ans++;
			else{
				cout<<ans+1<<'\n';
				return 0;
			} 
		}
	}
	else if(!flag2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			p[i]=p[i-1]+sp;
			if(m>=p[i]) ans++;
			else{
				cout<<ans+1<<'\n';
				return 0;
			} 
		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		val[i]=val[i-1]+(a[i]-a[i-1]);
		p[i]=p[i-1]+val[i];
	}
	for(int id=1;id<=n;id++){
		long long ans=0,p=m;
		for(int i=1;i<=n;i++){
			if(a[i]>a[id]) val[i]=1000000000000000000;
	    	else val[i]=a[id]-a[i];
		}
		sort(val+1,val+n+1);
		for(int i=1;i<=n;i++){
			if(p>=val[i]){
				p-=val[i];
				ans++;
			}
			else{
				break;
			}
		}
		res=max(res,ans);
	}
	cout<<res<<'\n';
	return 0;
}
