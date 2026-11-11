#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w,a,t,x,y,k;
int main(){
	freopen("subway.in","r",stdin);	
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>w;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a>>t;
		}
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
		cout<<((x+y*5)%676767*(a/k*t/q)%676767+m*c-a+x*x-y*y-3)<<endl;
	}
	return 0;
} 
