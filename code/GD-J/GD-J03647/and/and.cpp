#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200009],ans=-1;
bool b;
void dfs(ll now,ll sum,ll nowx){
	if(nowx==m){
		ans=max(ans,sum);
		return ;
	}
	if(n-now+1<m-nowx) return ;
	else if(n-now+1==m-nowx) dfs(now+1,sum&a[now],nowx+1);
	else{
		dfs(now+1,sum&a[now],nowx+1);
		dfs(now+1,sum,nowx);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(pow(2,(ll)log(a[i]))!=n) b=1;
	}
	if(!b){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(m==1){
		ll mx=-1;
		for(ll i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(m==2){
		ll mx=-1;
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		ll sum=a[1];
		for(ll i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	if(n<=20){
		dfs(1,pow(2,50)-1,0);
		cout<<ans;
	}
	if(pow(2,(ll)log(n))==n){
		cout<<a[n-m+1];
		return 0;
	}
	sort(a+1,a+n+1);
	ll num=a[n-m+1];
	for(ll i=n-m+2;i<=n;i++){
		num&=a[i];
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
} 
