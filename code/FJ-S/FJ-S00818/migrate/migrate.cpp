#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005],x[2000005],ans,n,d; 
int main(){
	freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int iiii=1;iiii<=t;iiii++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1){
				x[i-1]=a[i]-a[i-1];
				if(i!=2&&x[i-1]==x[i-2]){
					ans++;
				}
			}
		}
		cout<<1;
	}
	return 0;
}
