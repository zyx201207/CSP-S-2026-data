#include<bits/stdc++.h>
using namespace std;
const int N=200005;
using ll =long long ;
struct  Node{
	ll cnt;
	char  a;
};
ll ans;
vector <Node> t;
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x; char y;
		cin>>x>>y;
		t.push_back({x,y});
	}
	int l=0,r=n-1;
	int tolt=n;
//	cout<<l<<" "<<r;
     while(tolt>1){
     	ll x=t[l].cnt;
     	ll y=t[r].cnt;
     	if(x>y){
     		if(t[l].a!=t[r].a){
     			ans+=y;
			 }	
			  t[l].cnt-=y;
     		   r--;
     		   tolt--;	
		 }
     	else if(y>x) {
     		if(t[l].a!=t[r].a){
     			ans+=x;
			 }
     		t[r].cnt-=x;
     		tolt--;
     		l++;
		 }
     	else {
     		if(t[l].a!=t[r].a){
     			ans+=x;
			 }
     		tolt-=2;
     		r--; l++;
		 }
	 }
	cout<<ans;
	return 0;
} 
