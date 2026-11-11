#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
void fast(){
	 ios::sync_with_stdio(0);
	 cin.tie(0),cout.tie(0);
	 return ;
}
ll a[N];
signed main(){
	   fast();
	  freopen("crystal.in","r",stdin);
	  freopen("crystal.out","w",stdout);
	   ll n,m,ans=0;
	   cin>>n>>m;
	   for(int i=1;i<=n;i++){
	   	cin>>a[i];
	   }
		sort(a+1,a+n+1);
		ll o=a[2]-a[1];
		for(int i=1;i<=n;i++){
			o=a[i+1]-a[i];
			m-=i*o;
			if(m<0){
				cout<<i;
				return 0;
			}
		}cout<<n;
	   return 0;
}
  

