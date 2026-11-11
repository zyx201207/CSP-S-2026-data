#include<bits/stdc++.h>
using namespace std;
struct draw{
	char shu;
	long long id;
};
long long n,r,mi,ans;
char l;
deque<draw> v;
stack<draw> w;
int main(  ){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r>>l;
		v.push_back({l,r});
		w.push({l,r});
	}
	while(v.empty( )==0){
		mi=min(v.front( ).id,w.top( ).id);
		if(v.front( ).shu!=w.top( ).shu){
			ans+=mi;
		}
		l=v.front( ).shu;
		r=v.front( ).id;
		v.pop_front( );
		if(r>mi) v.push_front({l,r-mi});
		l=w.top( ).shu;
		r=w.top( ).id;
		w.pop( );
		if(r>mi) w.push({l,r-mi});
	}
	cout<<ans/2;
	return 0;
} 
