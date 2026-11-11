#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ll a[200000] = {};
//char x[200000] = {};
//ll cnt[30] = {};
char a[1000000] = {};
int main()
{
	//:(
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ll n,lo = 0,num = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		ll x;
		char y;
		cin>>x>>y;
		ll now = x;
		while(now >= 1){
			a[++lo] = y;
			now--;
		}
	}
	
	for(int i = 1;i <= lo / 2;i++){
		if(a[i] != a[lo - i + 1]){
			num++;
		}
	}
	cout << num;
	/*ll n,num = 0;
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	string s;
	for(int i = 1;i <= n;i++){
		cin>>a[i]>>x[i];
		cnt[int(x[i]) - 96] += a[i];
	}
	
	for(int i = 1;i <= n / 2;i++){
		if(x[i] != x[i] - x[n - i + 1]){
			if(cnt[x[i]] > cnt[x[n - i + 1]]){
				num += x[n - i + 1];
				x[n - i + 1] = x[i];
			}else{
				num += x[i];
				x[i] = x[n - i + 1];
			}
		}
		
		if(a[i] != a[n - i + 1]){
			if(a[i] != a[n - i + 1]){
				if(a[i] - a[n - i + 1] > 0){
					ll z = a[i] - a[n - i + 1]; 
					ll now = n - i;
					while(z > 0 || x[i] != x[i + 1]){
						if(z - a[now] >= 0){
							z -= a[now];
							num += x[now];
							x[now] = x[i];
						}else{
							a[now] -= z;
							a[now + 1] += z;
							num += z;
							break;
						}
						now--;
					}
				}else{
					num += a[n - i + 1] - a[i];
					a[i] += a[i] - a[n - i + 1];
					a[i + 1] -= a[i] - a[n - i + 1];
				}
			}	
		}
	}*/ 
	return 0;
}
/*
3
2 a
2 b
1 c
*/
