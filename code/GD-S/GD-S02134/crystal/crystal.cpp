#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=5e5+5;
ll n,m,a[N],power,times,cnt=1;
//power：当前被合成大水晶的能量值 
//times：加能量所耗掉的操作次数 
//cnt：当前合成能量值下最大合成水晶个数 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	if(m>100000000){//特殊性质AB,13~18 
		cin>>n>>m;
		for(ll i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		power=a[1];
		for(ll i=2;i<=n;i++){//以a[i]为标准去合成 
			ll add=a[i]-power;
			power=a[i];
			times+=(i-1)*add;
			if(times>m) break;
			cnt=max(cnt,i);
		}
		cout<<cnt;
	}
	else{//常规,1~9 
		cin>>n>>m;
		for(ll i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(ll st=1;st<=(n-cnt+1);st++){//考虑第st个水晶到第n个水晶 
			power=a[st];
			times=0;
			for(ll i=st+1;i<=n;i++){//以a[i]为标准去合成 
				ll add=a[i]-power;
				power=a[i];
				times+=(i-st)*add;
				if(times>m) break;
				cnt=max(cnt,i-st+1);
			}
		}
		cout<<cnt;
	}
	
	
	
	return 0;
}


