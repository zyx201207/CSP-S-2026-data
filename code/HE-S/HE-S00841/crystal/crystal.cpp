#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+5;
ll n,a[N],m,now=0,ans=-1;

bool cmp(ll x,ll y){
	return x>y;
}
signed main(){
	cin.tie(0);
	cout.tie(0);
 	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	/*
	5 5
	1 2 4 8 9
	9 8 4 2 1
	*/
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	/*for(ll i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}*/
	for(ll i=1;i<=n;i++){//以第i个为基准  
		now=0;ll s=m;//now表示当前可以有几个水晶合成,s是临时变量，检测剩余次数 
		for(ll j=i;j<=n;j++){//因为已经sort过,并now赋值为1 ，所以从第i+1个开始找 
		    if(a[j]==a[i]) now++; 
			else if(a[j]<a[i]&&a[i]-a[j]<=s){//如果有比自己小的水晶并且还有足够操作次数的
				s-=a[i]-a[j];
				now++;
			}
		}
		if(now>=ans) {
			ans=now; 
		}
	}
	cout<<ans;
	return 0;
}
/*
思路
i为基准，找到能使水晶数量最多的i 
先帝创业未半而中道崩殂今天下三分益州疲弊
危急存亡！ 
*/ 
