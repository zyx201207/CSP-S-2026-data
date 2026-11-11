#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using str=string;
ll n;
ll const N=2e5+10;
struct node{
	ll a;
	char c;
};
struct stru{
	ll i,j;
};
node a[N],b[N],c;
node anms[N];
vector<node>v;
bool cmp(node x,node y){
	return x.c<=y.c;
}
str sa="",sb="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;/*
	for(ll i=1;i<=n/2;i++){
		cin>>a[i].a>>a[i].c;
	}
	bool half_bool=false;
	if(n%2==1){
		cin>>c.a>>c.c;
		half_bool=true;
	}
	ll next_plus;
	for(ll i=n/2;i>=0;i--){
		cin>>b[i].a>>b[i].c;
		if(a[i].c!=b[i].c){
			anms[i].a+=min(a[i].a-next_plus,b[i].a);
			
			next_plus=max(a[i].a,b[i].a)-min(a[i].a,b[i].a);
		}
	}
	*/
	
	for(ll i=1;i<=n;i++){
		ll x;
		char y;
		cin>>x>>y;
		for(ll j=1;j<=x;j++){
			sa[i]+=y;
		}
	}
	for(ll i=n;i>n/2;i--){
		sb+=sa[i];
	}
	
	ll ans_=0;
	for(ll i=0;i<sb.size();i++){
		if(sa[i]!=sb[i]){
			ans_++;
			//cout<<sa[i]<<' '<<sb[i]<<' ';
		}
	}
	cout<<ans_;
	fclose(stdin);
	fclose(stdout);
	return  0;
}
/*
3
2a
2b
1c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
