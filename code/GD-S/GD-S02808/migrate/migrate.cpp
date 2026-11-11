#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[101000];
int f[200010],ans;
long long cnt[200100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	cin>>c>>t;
	while(t--){
		ans = 0;
		cin>>n>>d;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			cnt[i] = 0;
			f[i] = 1e9;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				f[j] = 1e9;
				cnt[j] = 0;
			}
			f[i] = 0;
			cnt[i] = 1;
			int tmp = 0;
			for(int j= i+1;j <= n;j++){
				for(int k = j-1;k>=i;k--){
					if(a[j]-a[k]>d)break;
					//cout<<j<<" "<<k<<" "<<i<<" "<<f[k]<<" "<<cnt[k]<<endl;
					if(f[j] > f[k]+1){
						f[j] = f[k]+1;
						cnt[j] = cnt[k];
					}
					else if(f[j] == f[k]+1){
						cnt[j]+=cnt[k];
					}
				}
			
				if(cnt[j]==2){
					ans++;
				}
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
} 
