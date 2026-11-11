#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const ll Mod=1e18;
ll a[N],cf[N],cnt=0;
ll n,m;
bool flga=1,flgb=1;
//25+0+8+0 oh no
//xue guo dan wang le
// lnzz
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			flga=0;
		}
	}
	for(int i=2;i<=n;i++){
		cf[i]=abs(a[i]-a[i-1]);
		if(cf[i]!=cf[i-1]&&i>2){
			flgb=0;
		}
		//2*10^12 < 1e18
	}
	if(flga){
		int cnta=0;
		for(int i=2;i<=n;i++){
			if(m<i-1||m<=0){
				break;
			}
			cnta++;
			m-=i+1;
		}
		cout<<cnta+1;
		return 0;
	}
	if(flgb){
		if(cf[3]==0){
			cout<<n;
			return 0;
		}
		int cnta=0;
		for(int i=2;i<=n;i++){
			if(m<i-1||m<=0){
				break;
			}
			cnta++;
			m-=(i*cf[3]+1);
		}
		cout<<cnta;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(m<cf[i]||m<=0){
			break;
		}
		cnt++;
		m-=abs(cf[i]);
	}
	cout<<cnt+1;
	return 0;
} 