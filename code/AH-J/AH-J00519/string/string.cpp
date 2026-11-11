#include<bits/stdc++.h>
using namespace std;
#define MAXN 200042
#define ll long long
struct ki{
	ll num;
	char how;
}k[MAXN];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin>>n;
	int y = 1;
	for(int i=1;i<=n;i++){
		ll a;
		char b;
		cin>>a>>b;
		if(y>1 && b == k[y-1].how){
			k[y-1].num += a;
			continue;
		}
		k[y].how = b;
		k[y].num = a;
		y++;
	}
	y--;
	ll ans = 0;
	ll t = 0;
	for(int i=1;i<=y/2;i++){
		int j = y-i+1;
		if(k[i].how == k[j].how) continue;
		int ax = i;
		int in = j;
		if(k[i].num < k[j].num) swap(ax,in);
		
		if(k[in].num >= t){
			ans += t;
			ans += k[in].num-t;
			t = k[ax].num - (k[in].num- t);
		}else{
			t -= k[in].num;
			t += k[ax].num;
			ans += k[in].num;
		}
	}
	if(t) ans+=t-1;
	cout<<ans;
	
	
	return 0;
	fclose(stdin);
	fclose(stdout);
}

