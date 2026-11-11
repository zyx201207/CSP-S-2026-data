#include<bits/stdc++.h>
using namespace std;
long long b[2000005];
long long a[6000005];
long long vis[6000005];
struct stu{
	bool b;
	long long last;
};
stu cz[6000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool cx = 1;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] < a[i - 1]) cx = 0;
	}
	if(cx){
		for(int i = 1;i <= n;i++) b[a[i]]++;
		long long ans = 0;
		for(int i = 1;i <= m;i++){
			ans += b[i];
			cout<<ans<<" ";
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cz[j].b = 0;
			cz[j].last = 0;
		}
		memset(vis,0,sizeof(vis));
		for(int j = 1;j < i;j++){
			vis[j] = 1;
		}
		for(int j = i;j <= n;j++){
			if(cz[a[j]].b){
				for(int k = cz[a[j]].last;k < j;k++){
					vis[k] = 1;
					cz[a[k]].b = 0;
					cz[a[k]].last = 0;
				}
				cz[a[j]].b = 1;
				cz[a[j]].last = j;
			}else{
				cz[a[j]].b = 1;
				cz[a[j]].last = j;
			}
		}
		for(int j = 1;j <= n;j++){
			if(vis[j] == 0) b[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
