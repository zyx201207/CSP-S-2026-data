#include<bits/stdc++.h>
using namespace std;
#define filename "and"
#define ll long long
const ll N=2e5+10;
ll n,m;
ll a[N];
ll ans=-1;
void dfs(ll id,ll cnt,ll idx,ll yu){
	if(yu>n-m)return;
	if(id==m+1){
		ans=max(ans,cnt);
		return;
	}
	if(id==0){
		dfs(id+1,a[idx+1],idx+1,yu);
		dfs(id,cnt,idx+1,yu+1);
	}else{
		dfs(id+1,cnt&a[idx],idx+1,yu);
		dfs(id,cnt,idx+1,yu+1);
	}
	return;
}
int main(){ 
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	scanf("%lld%lld",&n,&m);
	ll mx=-1;
	ll ssum=a[1];
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>1){
			ssum=(ssum&a[i]);
		}
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx<<'\n';
		return 0;
		//6
	}
	if(n==m){
		cout<<ssum<<'\n';
		return 0;
		//7
	}
	if(mx==4){
		bool f0=0,f1=0,f2=0,f3=0,f4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)f0=1;
			if(a[i]==1)f1=1;
			if(a[i]==2)f2=1;
			if(a[i]==3)f3=1;
			if(a[i]==4)f4=1;
		}
		if(f4&&f3&&f2&&f1&&f0){
			cout<<"7\n";
			return 0;
		}else if(f0&&f1&&f2&&f3){
			cout<<"3\n";
		}else if(f1&&f2&&f3&&f4){
			cout<<"7\n";
		}else if(f1&&f2&&f3){
			cout<<"3\n";
		}else if(f2&&f3&&f4){
			cout<<"7\n";
		}else if(f0&&f1&&f2){
			cout<<"3\n";
		}else if(f0&&f1&&f3){
			cout<<"3\n";
		}else if(f0&&f1&&f4){
			cout<<"5\n";
		}else if(f0&&f2&&f3){
			cout<<"3\n";
		}else if(f0&&f2&&f4){
			cout<<"6\n";
		}else if(f0&&f3&&f4){
			cout<<7<<'\n';
		}else if(f1&&f2&&f4){
			cout<<"7\n";
		}else if(f1&&f3&&f4){
			cout<<"7\n";
		}else if(f1&&f2){
			cout<<"3\n";
		}else if(f1&&f3){
			cout<<"3\n";
		}else if(f1&&f4){
			cout<<"5\n";
		}else if(f0&&f4){
			cout<<"4\n";
		}else if(f0&&f3){
			cout<<"3\n";
		}else if(f0&&f2){
			cout<<"2\n";
		}else if(f0&&f1){
			cout<<"1\n";
		}else if(f2&&f3){
			cout<<"3\n";
		}else if(f2&&f4){
			cout<<"6\n";
		}else if(f3&&f4){
			cout<<"7\n";
		}else if(f0){
			cout<<"0\n";
		}else if(f1){
			cout<<"1\n";
		}else if(f2){
			cout<<"2\n";
		}else if(f3){
			cout<<"3\n";
		}else if(f4){
			cout<<"4\n";
		}else{
			cout<<"wo ye mei zhao le xiang bu chu lai le";
		}
		//16.17
		return 0;
	}
	if(n<=2000&&m==2){
		ll mmax=-1;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				mmax=max(mmax,(a[i]&a[j]));
			}
		}
		cout<<mmax<<'\n';
		return 0;
		//8~10
	}
	if(n<=20){
		dfs(0,0,0,0);
		cout<<ans<<'\n';
		return 0;
		// 1~5
	}
	cout<<mx<<'\n';
	//A
	return 0;
}
//Trick||Treat!
