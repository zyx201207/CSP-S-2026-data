#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t,x[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    cin>>n>>d;
	    for(int i=1;i<=n;i++) cin>>x[i];
	    int dp=x[2]-x[1];
	    if(d>=2*dp&&d<3*dp) cout<<n-3<<endl;
	    else cout<<'0'<<endl;
    }
    return 0;
}
