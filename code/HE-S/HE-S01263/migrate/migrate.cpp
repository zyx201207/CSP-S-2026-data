#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
long long a[maxn],sum[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){  
		int n,d;
		cin >> n >> d;
		int flag=0;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			sum[i]=a[i]-a[i-1];
		}
		for(int i=3;i<=n;i++){
			if(sum[i]!=sum[i-1])flag=1;
		}
		if(flag==0){
			if(d%2!=0)d++;
			long long ans=n-(d*3)/2;
			if(ans>=0)cout <<ans<<endl;
			else cout <<0;
		}
	}
	return 0;
}
