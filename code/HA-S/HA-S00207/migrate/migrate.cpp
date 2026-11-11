#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,T,n;
ll a[2000010],d,ans;
int sPath(int l,int r){
	int ans=0;
	int l1=l;
	for(;l1<r;ans++){
		bool b=1;
		for(int i=l1+1;i<=n;i++){
			if((i==n)&&(a[n]<=a[l1]+d)){
				l1=n;b=0;break;
			}
			if(a[i]<=a[l1]+d&&a[i+1]>a[l1]+d){
				l1=i;
				b=0;
				break;
			}
		}
		if(b)return -1;
	}
	return ans;
}
int dfs(int l,int r,int sp){
	int cnt=0;
	if(sp==0){
		if(l==r)return 1;
		else return 0;
	}
	for(int i=l+1;i<=r;i++){
		if(a[i]>a[l]+d)break;
		cnt+=dfs(i,r,sp-1);
	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			ll k=a[2]-a[1];
			if(d<k*2){
				cout<<"0\n";
				continue;
			}
			else{
				ll t=d/k;
				for(int i=1;i<=n;i++)
					if((a[n]-a[i]-t*k)/k>=t-1)ans+=1;
			}
			cout<<ans<<'\n';
		}
	}else{
		while(T--){
			ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int sp=sPath(i,j);
					if(sp<=1)continue;
					if(dfs(i,j,sp)==2)ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}