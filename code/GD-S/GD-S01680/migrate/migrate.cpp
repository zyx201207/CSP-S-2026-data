#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+10;

ll c,t;
void bfs(int lgst){
	
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
    	ll n,d,x[N];
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)cin>>x[i];
    	ll longest=d/(x[2]-x[1]);
    	if(longest>=2)cout<<n/2<<endl;
	}
}



















