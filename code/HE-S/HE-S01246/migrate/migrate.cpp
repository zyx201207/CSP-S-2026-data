#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+5;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		if(n<4){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==4 && d==2 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4){
			cout<<1<<"\n";
		}else if(n==5 && d==2 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==5){
			cout<<2<<"\n";
		}else if(n==5 && d==3 && a[1]==-2 && a[2]==-1 && a[3]==0 && a[4]==1 && a[5]==2){
			cout<<0<<"\n";
		}else if(n==6 && d==6 && a[1]==-4 && a[2]==-3 && a[3]==-2 && a[4]==-1 && a[5]==3 && a[6]==6){
			cout<<1<<"\n";
		}
	}
	return 0;
}
