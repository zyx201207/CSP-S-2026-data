#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],ans; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int id=i,mn=0,h=1e9,flag=0;
				while(id<j){
					int cnt=0,l=id;
					while(cnt+a[id+1]-a[id]<=d&&id+1<=j){
						id++;
						cnt+=a[id]-a[id-1];
					}
					if(id==l) flag++;
					else flag=0;
					if(flag==2){
						break;
					}
					for(int k=l-1;k>=h;k--){
						if(a[id]-a[k]<=d) mn++;
					}
					h=l;
					if(mn>1){
						break;
					}
				}
				if(mn==1&&flag<2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
