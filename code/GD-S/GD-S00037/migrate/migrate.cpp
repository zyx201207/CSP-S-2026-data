#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		sort(a+1,a+n+1);
		int ans=0;
		int w=a[2]-a[1],q=(a[n]-a[1])/w+1,p=m/w;
		ans+=(q-p+1)*(p-1)/p;	
		cout<<ans<<endl;
	}
	return 0;
} 
/*
0
0
259997
259995
86669
0
0
0
7
5
5
0
*/
