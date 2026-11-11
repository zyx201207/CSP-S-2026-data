//GZ-S00270 贵阳三中 王志栋 
#include<bits/stdc++.h>
using namespace std;

int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans = 0;
		int n,d;
		cin>>n>>d;
		vector<int>a(n + 1),s(n + 1);
		vector<int>dis(n + 1,1e9);
		for(int i = 1;i <= n;i++){
			cin>>a[i];
		}
		dis[1] = 0;
		for(int i = 1;i <= n;i++){
			if(a[i] == 0)continue;
			for(int k = i + 1;a[k] - a[i] <= d;k++){
				if(a[k] == 0)continue;
				if(dis[i] + 1 < dis[k]){
//					cout<<dis[i] + a[k] - a[i]<<endl;
					dis[k] = dis[i] + 1;
					s[k] = 0;
				}
				else if(dis[i] + 1 == dis[k]){
					s[k]++;
				}
				for(int j = k + 1;a[j] - a[k] <= d;j++){
					if(a[j] == 0)continue;
					if(dis[k] + 1 < dis[j]){
						dis[j] = dis[k] + 1;
						s[j] = 0;
					}
					else if(dis[k] + 1 == dis[j]){
						s[j]++;
					}
				}
			}
		}
		for(int i = 1;i <= n;i++){
//			cout<<dis[i]<<" "<<s[i];
//			cout<<endl;
			if(s[i] != 0 && s[i] % 2 == 0)ans++;
		}
		cout<<ans<<endl;
		
	}
}
