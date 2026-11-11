#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
struct Node{
	int ans;
	char c;
}a[N];
int n,ans,zs,ys;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++){
		cin>>a[i].ans>>a[i].c;
	}
	int h = 1,t = n;
	while(h < t){
		if(zs == 0 && ys == 0){
			if(a[h].ans >= a[t].ans){
				if(a[h].c != a[t].c){
					cout<<h<<' '<<t<<' '<<a[t].ans<<endl;
					ans += a[t].ans;
				}
				zs = a[h].ans - a[t].ans;
				t--;
			}else{
				if(a[h].c != a[t].c){
					ans += a[h].ans;
				}
				ys = a[t].ans - a[h].ans;
				h++;
			}
		}else if(zs != 0){
			if(a[t].ans >= zs){
				if(a[h].c != a[t].c){
					ans += zs;
				}
				zs = 0;
				ys = a[t].ans - zs;
				h++;
			}else{
				if(a[h].c != a[t].c){
					ans += a[t].ans;
				}
				zs -= a[t].ans;
				t--;
			}
		}else if(ys != 0){
			if(a[h].ans >= ys){
				if(a[h].c != a[t].c){
					ans += ys;
				}
				ys = 0;
				zs = a[h].ans - ys;
				t--;
			}else{
				if(a[h].c != a[t].c){
					ans += a[h].ans;
				}
				ys -= a[h].ans;
				h++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
