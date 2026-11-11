#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,n,d,a[2100000];
int s[2100000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(C==11||C==12){
			if(a[3]-a[1]>d){
				cout<<0<<"\n"; 
			}else{
				cout<<n*(n-3)/2;
			}continue;
		}int ans=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d){
				s[i]=1,s[i+3]=2;
				i=i+4;
			}
		}
		for(int i=1;i<=n;i++){
			cout<<i<<": "<<s[i]<<"\n";
		}
		for(int i=1;i<=n;i++){
			bool ok=0,ok2=0;
			for(int j=i;j<=n;j++){
				if(s[j]==1){
					if(!ok){
						ok=1;
					}else{
						if(ok2)ans+=3;
						break;
					}
				}else if(s[j]==2){
					if(!ok)continue;
					ok2=1;ans+=1; 
				}else if(ok&&ok2){
					ans+=1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
