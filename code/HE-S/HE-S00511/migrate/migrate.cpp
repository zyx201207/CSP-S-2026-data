#include<bits/stdc++.h>
using namespace std;
int c,t;
int m[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,k,s=0,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>m[i];
		}
		k=m[2]-m[1];
		for(int i=1;i<=n&&s<n-1;i++){
			int cnt=m[1]+d*2-k;
//			cout<<cnt;
			for(int j=1;j<=n;j++){
				if(m[j]-m[i-1]+1>cnt){
					s=j-1;
					break;
				}
			}
//			cout<<s;
			if(s+i-3==2)ans++;
		}
		cout<<ans;
	}
	return 0;
}
