#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,t;
int a[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<=2000005;i++){
			a[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool f1=0;
		int d1=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(d1!=a[i]-a[i-1]){
				f1=1;
			}
		}
		if(!f1){
			int s1=floor(d/d1);
			int ss=0;
			if(s1<=1||s1>=3){
				cout<<0<<endl;
				continue;
			}
			for(int i=s1+1;i<=s1+s1-1;i++){
				ss+=(n-i);
			}
			cout<<ss<<endl;
		}
	}
	return 0;
}
