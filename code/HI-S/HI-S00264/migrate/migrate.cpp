#include <bits/stdc++.h>
using namespace std;
int c,t,a[2000005],d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,ans=0,s=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int l=i+1;
			for(int j=l;j<=n;j++){
				if(a[j]-a[i]<=d){
					ans++;
				}
			}
			if(ans==2)s++;
		}
		cout<<s;
	}
	return 0;
}
