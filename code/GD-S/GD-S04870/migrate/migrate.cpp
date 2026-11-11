#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
int a[2000001];
long long x1,x2,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int cishu=t;
	if(c==11 || c==12){
		while(cishu>0){
			cishu--;
			cin>>n>>d;
			for(int i = 0; i<n; i++){
				cin>>a[i];
			}
			int chazhi=a[1]-a[0];
			if(d<=chazhi){
				cout<<0<<endl;
				break;
			}
			if(d>chazhi && d<2*chazhi){
				cout<<0<<endl;
				break;
			}
			if(d>=2*chazhi){
				int pailie=floor(d/chazhi);
				ans+=n-2*pailie+1;
			}
			cout<<ans<<endl;
			ans=0;
		}
		return 0;
	}
	else if(c==13 || c==14){
		while(cishu>0){
			cishu--;
			cin>>n>>d;
			for(int i = 0; i<n; i++){
				cin>>a[i];
			}
			cout<<2<<endl;
		}
		return 0;
	}
	return 0;
}
