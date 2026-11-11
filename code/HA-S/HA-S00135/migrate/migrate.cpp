#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0;
		cin>>n>>d;
		long long a[n+1]={0},s[n+1]={0};
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>0;j--){
				if(a[j]+d>=a[i])s[i]++;
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]==2)ans++;
		}
		cout<<ans>=0?ans:0<<'\n';
	}
	return 0;
}
