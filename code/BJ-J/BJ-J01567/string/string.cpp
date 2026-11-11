#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll l;
	char c;
}a;
deque<node> st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a.l>>a.c;
		st.push_back(a);
	}
	ll ans=0;
	while(st.size()){
		if(st.size()==1)break;
		node l=st.front();
		st.pop_front();
		node r=st.back();
		st.pop_back();
		if(l.l>r.l){
			st.push_front({l.l-r.l,l.c});
			if(l.c!=r.c)ans+=r.l;
		}else if(l.l==r.l){
			if(l.c!=r.c)ans+=r.l;
		}else{
			st.push_back({r.l-l.l,r.c});
			if(l.c!=r.c)ans+=l.l;
		}
	}
	cout<<ans;
	return 0;
}
