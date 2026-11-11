#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n,d;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int sel=a[2]-a[1];
			int k=d/sel;
			if(k<=1){
				cout<<0<<endl;
			}
			else{
				cout<<max(n-(k*2)+1,0)<<endl;
			}
		}
	}
	else{
		while(t--) cout<<0<<endl;
	}
	return 0;
}
