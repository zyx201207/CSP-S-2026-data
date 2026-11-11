#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[10000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n<=3){
			cout<<0<<"\n";
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d<=a[2]-a[1]){
			cout<<0<<"\n";continue;
		}else {
			int dd=d/(a[2]-a[1]);
			if(dd<=2)cout<<n-dd*2+1<<"\n";
			else
			cout<<(n-dd+1)*(n-dd)/2<<"\n";
		}
	}
	return 0; 
}
