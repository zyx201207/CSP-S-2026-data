#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,d;
int x[310];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			int num = 0;
			for(int j=i+1;j<=n;j++){
				if(x[j] < x[i]+d)num++;
				if(x[j] > x[i]+d)break;
				if(x[j] == x[i]+d){
					num = 0;
					break;
				}
			}
			if(num == 2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
