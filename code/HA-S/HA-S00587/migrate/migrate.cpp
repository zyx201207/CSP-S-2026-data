#include <bits/stdc++.h>
using namespace std;
//dp
const int N = 2e6+10;
long long a[N];
int c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cout.tie(0);
	scanf("%d%d",&c,&t);
	
	while(t--){
		int ans = 0;
		memset(a,0,sizeof(a));
		scanf("%d%d",&n,&d);
		for(int i = 1;i <= n;i++){
			scanf("%ld",&a[i]);
		}
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				if((j-i+1)/d >= d){
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
