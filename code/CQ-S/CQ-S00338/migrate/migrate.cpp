#include<bits/stdc++.h>
using namespace std;
long long x[2005000];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> x[i];
		}
		long long ans=0;
		int bl=1,bl2=0;
		bool js=0;
		for(int i=0;i<n;i++){
			if(i<n-1&&x[i+1]-x[i]>d)bl=1,js=0;
			else if(i<n-2&&x[i+2]-x[i]>d){
				if(js)bl2++,ans+=bl;
				else bl++;
			}
			else if(i<n-3&&x[i+3]-x[i]>d){
				if(js)bl2++,ans+=bl;
				else bl++;
				if(js==0){
					js==1;
					ans+=bl;
					bl2=1;
				}
				else{
					bl=bl2;
					bl2=1;
					ans+=bl;
				}
			}
			else {
				if(js)bl2++,ans+=bl;
				else bl++;
				if(js==0){
					js==1;
					ans+=bl;
					bl2=1;
				}
				else{
					bl=bl2;
					bl2=1;
					ans+=bl;
				}
				bl=1,js=0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
