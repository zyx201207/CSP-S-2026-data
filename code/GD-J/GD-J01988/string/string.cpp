#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct node{
	ll a;
	char ch;
};
vector<node> s;
void init(){
	cin>>n;
	ll ans=0;
	ll a;
	char ch;
	for(int i=1;i<=n;i++){
		cin>>a>>ch;
		if(s.empty()){
			s.push_back({a,ch});
			ans+=a;
			continue;
		}
		if(s.back().ch==ch){
			node x=s.front();
			//cout<<ans<<'\n';
			ans+=a;
		}else{
			node x=s.back();
			//cout<<x.ch<<'\n';
			s.pop_back();
			s.push_back({ans,x.ch});
			ans=a;
			s.push_back({ans,ch});
		}
	}
	node x=s.back();
	//cout<<x.ch<<'\n';
	s.pop_back();
	s.push_back({ans,x.ch});	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	if(s.size()==1){
		cout<<0;
		return 0;
	}
	ll ans=0;
	for(;s.size()!=1;){
		if(s.empty())
			break;
		node x=s.front(),y=s.back();
		if(x.a==y.a and x.ch!=y.ch){
			ans+=x.a;
			s.pop_back();
			reverse(s.begin(),s.end());
			s.pop_back();
			reverse(s.begin(),s.end());
		}else if(x.a==y.a and x.ch==y.ch){
			s.pop_back();
			reverse(s.begin(),s.end());
			s.pop_back();
			reverse(s.begin(),s.end());			
		}else if(x.a>y.a and x.ch!=y.ch){
			ans+=y.a;
			x.a-=y.a;
			s.pop_back();
			s.push_back({x.a,x.ch});
			reverse(s.begin(),s.end());
			s.pop_back();
			reverse(s.begin(),s.end());			
		}else if(x.a>y.a and x.ch==y.ch){
			x.a-=y.a;
			s.pop_back();
			s.push_back({x.a,x.ch});
			reverse(s.begin(),s.end());
			s.pop_back();
			reverse(s.begin(),s.end());	
		}else if(x.a<y.a and x.ch!=y.ch){
			ans+=x.a;
			y.a-=x.a;
			s.pop_back();
			reverse(s.begin(),s.end());
			s.pop_back();
			s.push_back({y.a,y.ch});
			reverse(s.begin(),s.end());			
		}else if(x.a<y.a and x.ch==y.ch){
			y.a-=x.a;
			s.pop_back();
			reverse(s.begin(),s.end());
			s.pop_back();
			s.push_back({y.a,y.ch});
			reverse(s.begin(),s.end());		
		}
	}
	cout<<ans;
	return 0;
}
