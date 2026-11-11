#include <bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long c,t;
long long a[N],ans[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int j=1;j<=t;j++){
		long long dc=1;
		long long n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1&&(a[i-1]+1)!=a[i]){
				dc=0;
			}
		}
		if(dc==1){
			for(int i=1;i<=n/2;i++){
				if(i==1&&(m*2)<=n){
					ans[j]++;
				}else if(i>1&&((m*2)+(i-1))<=n){
					ans[j]++;
				}
			}
		}else{
			if(a[n]<m){
				cout<<0;
			}
		}
		for(int i=1;i<=n;i++){
			a[i]=0;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
