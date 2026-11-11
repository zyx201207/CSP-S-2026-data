#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,a[500010],cha[500010],maxx=-0x3f3f3f3f3f3f3f3f,cnt=1;
void upp(ll x,ll k){
	cnt=1;
	for(int i=x+1;i<=n;i++){
		if(a[i]<a[i-1]){
			i++;
		}else{
			if(cnt*cha[i]<=k){
				k-=cha[i]*cnt;
				cnt++;
			}else{
				return ;
			}
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(cha,0,sizeof(cha));
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	sort(a+1,a+1+n);

	for(int i=1;i<=n;i++){
		upp(i,m);
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
}
