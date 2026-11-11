#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[200005];
char b[200005];
int tong[200005][2],cc;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		ans+=a[i];
	}
	int h = ans%2;
	ans = ans/2;
	int ji = 0;
	int z = 0;
	for(int i = 1;i <= n;i++){
		if(ji+a[i] > ans){
			a[i]-=ans-ji+h;
			cc++;
			tong[cc][0] = ans-ji;
			tong[cc][1] = (int)b[i]-96;
			z = i;
			break;
		}else{
			ji+=a[i];
			cc++;
			tong[cc][0] = a[i];
			tong[cc][1] = (int)b[i]-96;
		}
	}
	int ans1 = 0;
	for(int i = z;i <= n;i++){
		while(a[i]){
			if(a[i] > tong[cc][0]){
				a[i]-=tong[cc][0];
				if((int)b[i]-96 != tong[cc][1]){
					ans1+=tong[cc][0];
				}
				tong[cc][0] = 0;
				cc--;
			}else{
				tong[cc][0]-=a[i];
				if((int)b[i]-96 != tong[cc][1]){
					ans1+=a[i];
				}
				break;
			}
		}
	}
	cout << ans1;
	return 0;
} 
