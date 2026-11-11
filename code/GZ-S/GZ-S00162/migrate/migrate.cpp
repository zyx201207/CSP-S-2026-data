//GZ-S00162 兴义市弘毅中学 付新峻羽
#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d,cnt=0,maxx=-9999999999999999;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>x[i];
			if(x[i]>maxx){
				maxx=x[i];
			}
		}
		for(int i = 1;i<=n;i++){
			long long end=x[i]+(d+d-1);
			if(end<=maxx){
				for(int j = n;j>=i;j--){
					if(x[j]==end){
						for(int q =i+1;q<=j;q++){
							if(x[i]+d==x[q] || x[i]+d-1==x[q]){
								cnt++;
								break;
							}
						}
					}
				}
			}
		}
		cout<<cnt<<"\n";
		cnt=0;
	}
	return 0;
}
