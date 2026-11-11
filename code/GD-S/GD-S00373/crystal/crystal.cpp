#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5e5+10;
ll n,m,a[maxn],dis[maxn],ch=1,mch=-1,cost,spa=1,spb=1,d;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)spa=0;
		if(i==2)d=a[2]-a[1];
		if(i>=3 && a[i]-a[i-1]!=d)spb=0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		if(i>=2)dis[i-1]=a[i]-a[i-1];
	}
	if(spa || spb){
		for(ll j=1;cost<=m,j<=n-1;j++){
			cost+=dis[j]*ch;
			if(cost<=m)ch++;
		}
		mch=max(ch,mch);
		cout<<mch<<'\n';
		return 0;
	}
	for(ll i=1;i<=n;i++){
		if(n-i+1<=mch)break;
		for(ll j=i;cost<=m,j<=n-1;j++){
			cost+=dis[j]*ch;
			if(cost<=m)ch++;
		}
		mch=max(ch,mch);
		cost=0;
		ch=1;
	}
	cout<<mch<<'\n';
	return 0;
}
