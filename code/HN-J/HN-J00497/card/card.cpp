#include<bits/stdc++.h>
using namespace std;
const int N=5*5e5+10;
typedef long long ll;
ll n,m;
ll a[N];
ll tong[3*5e5+10];
ll mn[N];
bool check(int x){
	for(int i=1;i<=n;i++){
		if(a[i]==x)return false;
	}
	return true;
}
ll findd(int x){
	for(int i=1;i<=n;i++){
		if(a[i]==x)return i;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll hh=1;
	while(hh<=n)
	{
		if(hh==n-1){
			tong[a[n]]++;
			break;
		}
		int cs=1;
		for(int i=hh;i<=n;i++){
			if(check(a[i])){
				mn[cs]=a[i];
				cs++;
			}
			else{
				
				cs=findd(a[i]);
				mn[cs]
			}
			
		}
		
	}
	return 0;
	
}
