#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d;
int x[1000005];
int main(){
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin>>c>>T;
	while (T--){
		cin>>n>>d;
		int cha[1000006];
		if (d==1){
			cout<<0<<endl; 
		}
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		for (int i=1;i<=n;i++){
			cha[i]=x[i+1]-x[i];
		}
		int ans=0;
		for (int i=1;i<=n;i++){
			int j=i+3;
			if (d>=(x[j]-x[i+1])&&d>=(x[j-1]-x[i])&&d>cha[i]&&d>cha[i+2]&&d<(x[j]-x[i])){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
