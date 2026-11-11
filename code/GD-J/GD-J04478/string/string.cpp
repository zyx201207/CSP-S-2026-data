#include<iostream>
#define ll long long
using namespace std;
pair<ll,char> p[200005];
int last,n,m;
ll l,ans;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		ll a;
		char b;
		cin>>a>>b;
		l+=a;
		if(b==p[m].second) p[m].first+=a;//合并同类项 
		else p[++m]=make_pair(a,b);
	}
	for(int i=1;i<=m/2+m%2;i++){
		if(p[i].first!=p[m-i+1].first){
			if(p[i].second!=p[m-i+1].second) ans+=max(p[i].first,p[m-i+1].first)-(i+1==m-i+1);
			else ans+=abs(p[i].first-p[m-i+1].first);
		}
		else if(p[i].second!=p[m-i+1].second) ans+=p[i].first;
	}
	cout<<ans;
	return 0;
}
