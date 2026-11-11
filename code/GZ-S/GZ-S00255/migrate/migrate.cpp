//GZ-S00255,贵阳市白云区第十八中学，杨钟源 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	long long ans = 0;
	for(int k  = 0;k < t;k++){
		long long n,d;
		ans=0;
		cin>>n>>d;
		long long x[n] = {};
		for(int i = 0;i < n;i++){
			cin>>x[i];
		}
		sort(x,x+n);
		for(int i = 0;i < n;i++){
			long long p = i;
			long long k = 0;
			while(p>0&&x[i]-x[p]<=d){
				p--;
				k++;
				if(k>2) break;
			}
			if(k==2) ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
