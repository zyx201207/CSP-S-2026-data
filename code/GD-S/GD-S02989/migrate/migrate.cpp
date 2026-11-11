#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int c, t, n, m;
int x[maxn], d[maxn];
int type[maxn]={1};
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		memset(x, 0, sizeof(x));
		memset(d, 0, sizeof(d)); 
		memset(type, 1, sizeof(type));
		cin >> n >> m;
		for(int i=1; i<=n; i++){
			cin >> x[i];
			d[i]=x[i]-x[i-1];
		}
		int ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if((x[j]-x[i])<=m){
					continue;
				}
				for(int k=i; k<j; k++){
					if(j-i-1==1)type[k]==2;
					if(j-i-1>1)type[k]==3;
				}
			} 
		}
		int a_1=0, b_1=0;
		bool pair=false;
		for(int i=1; i<=n; i++){
			if(type[i]==1){
				if(pair)b_1++;
				else a_1++;
			}else if(type[i]==2){
				if(pair){
					ans=max(ans, a_1*b_1);
					a_1=b_1;
				}else{
					pair=true;
				}
			}else{
				ans=max(ans, a_1*b_1);
				pair=false;
				a_1=b_1=0;
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
