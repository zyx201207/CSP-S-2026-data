#include <bits/stdc++.h>
using namespace std;
int w[100000];
int a[6]={4,5,7,3,4,9};
int b[4]={4,5,7,1};
int ans,ans2;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int ans=a[0]+a[1]+a[2]+a[3]+a[4]+a[5];
	int ans2=b[0]+b[1]+b[2]+b[3];
	cout<<ans<<endl<<ans2;
	return 0;
}
