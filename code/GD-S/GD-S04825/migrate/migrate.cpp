#include<bits/stdc++.h>
using namespace std;
int c,t,n,q,x;
long long d,a[2000010],ans;
bool p,f;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==2){
				x=a[i]-a[i-1];
			}
			if(i>=2&&x!=a[i]-a[i-1]){
				f=false;
			}
		}
		if(f){
			cout<<n-d/x*2+1;
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=a[i]+d+1;j<=a[i]+d+d-1;j++){
				if(j>n){
					break;
				}
				p=false;q=0;
				for(int k=i+1;;k++){
					if(a[k]>=j-d&&a[k]<=a[i]+d){
						q++;
					}
					if(a[k]==j){
						p=true;
						break;
					}else if(a[k]>j||k>n){
						break;
					}
				}
				if(p&&q==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6



*/
