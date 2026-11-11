#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0,f=1;char ch = getchar();
	while(ch < '0'||ch >'9'){if(ch == '-')f=-1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
const int N = 5e5+10;
ll a[N];
ll mx = 0;
ll n,m;
void bf(){
    sort(a+1,a+n+1);
	ll mx = 0;
	for(int i = 2;i <= n;i ++){
		ll cnt =1,num = m;
		for(int j = i-1;j >= 1;j--){
			if(num - (a[i]-a[j]) >= 0&&num - (a[i]-a[j]) <= num){
				num -= (a[i]-a[j]);
				cnt++;
			}else{
				break;
			}
		}
		mx = max(mx,cnt);
	}
	printf("%lld",mx);
}
ll vis[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

	n = read(),m = read();
	for(int i = 1;i <= n;i ++) {
        a[i] = read();
	}
	bf();
	return 0;
}
/*
5 5
1 2 4 8 9
*/
