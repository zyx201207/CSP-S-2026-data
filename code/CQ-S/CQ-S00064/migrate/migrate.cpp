#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t;
int n,d;
int a[N],b[N];

void work(){
	memset(a,0,sizeof(a));
	cin>>n>>d;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	int sum=0;
	for (int i=1;i<=n;i++){
		if( d>=b[i+1]+b[i+2] && d>=b[i+2]+b[i+3] && d<b[i+1]+b[i+2]+b[i+3]){
			sum++;
		}
	}
	cout<<sum<<"\n";
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		work();
	}
	
	return 0;
} 
