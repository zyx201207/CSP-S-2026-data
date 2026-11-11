#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll d;int c,t;
ll wz[2000020];
int ans[200020];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	for(int p=1;p<=t;p++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>wz[j];
		}
		int o=wz[2]-wz[1];int fl=1;
		for(int j=3;j<=n;j++){
			if(wz[j]-wz[j-1]!=o) fl=0;
		}
		if(fl==1){
			if(d/o!=2){
				ans[p]=0;continue; 
			}
			if(d/o==2){
				ans[p]=n-3;continue;
			}
		}
		if(wz[n]-wz[1]<=d){
			ans[p]=0;continue;
		}
		for(int i=1;i+3<=n;i++){
			int bv=i+3;
			if(wz[bv]-wz[i]>d){
				if(wz[bv]-wz[i+1]<=d&&wz[bv-1]-wz[i]<=d){
					ans[p]++;
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
