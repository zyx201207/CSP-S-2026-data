#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,k,a[2000005],T,b[2000005];
ll solve1(int x){
   	k=m/x;
   	ll sum=0;
   	for(int i=1;i<=(m/x-1);i++){
	    ll d=i+k;
	    if(n-d>0) sum+=(n-d);
    }
    return sum;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		   cin>>n>>m;
		   for(int i=1;i<=n;i++){
			   cin>>a[i];   
		   }
		   cout<<solve1(a[2]-a[1])<<endl;	
	}
	return 0;
}
