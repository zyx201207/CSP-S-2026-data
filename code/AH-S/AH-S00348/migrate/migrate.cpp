#include<bits/stdc++.h>
#define N 2000005
using namespace std;
int n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		if(c==0||c==11||c==12){
			int X=abs(x[2]-x[1]);
			int t=d/X;
			cout<<x[1]<<" "<<x[2]<<" "<<n<<" "<<d<<" "<<X<<" ";
			if(t!=1&&t!=0){
				cout<<max(0,n-t*2)<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}
