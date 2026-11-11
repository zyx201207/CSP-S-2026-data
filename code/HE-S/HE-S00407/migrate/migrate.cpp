#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//0×óÓÒ
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int jia=a[2]-a[1];
		if(d<jia*2){
			cout<<0<<'\n';
			continue;
		}
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		int jp=(d-(d%jia))/jia;
		if(jp<=1){
			cout<<0<<'\n';
			continue;
		}
		int ans=(n-jp-jp)*(jp-1);
		for(int i=1;i<=jp-1;i++){
			ans+=i;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
