#include<bits/stdc++.h>
using namespace std;

int c,t;
long long a[2000005],dp[2000005];
int f1[100000005];
int f2[100000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n,ans=0;
		long long d;
		cin >> n >> d;
		memset(f1,0,sizeof f1);
		memset(f2,0,sizeof f2);
		for(int i=1;i<=n;i++){
			cin >> a[i];
			if(a[i]>=0) f1[a[i]]=1;
			else f2[a[i]]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]==2*d-1 && ((f1[a[j]-d] && f1[a[i]+d] && a[j]>=0) || (f2[abs(a[j]-d)] && f2[abs(a[i]+d)] && a[j]<=0))) ans++;
			}
		}
		cout<< ans << endl;
	}
	return 0;
}
