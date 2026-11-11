#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		int a[10000];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=n;j>1;j--){
			a[j]=a[j]-a[j-1];
		}
		a[1]=0;
		int x=1,ans=0,sum=0,b=0;
		while(x<=n){
			if(a[x]>=d){
				sum=0;
				b=0;
			}else{
				sum+=a[x];
			}
			if(b==1){
				ans++;
			}
			if(sum%d==d-1 && sum!=d-1){
				ans++;
				b=1;
			}
			x++;
		}
		cout<<ans;
	}
	return 0;
}
