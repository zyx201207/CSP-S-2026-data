#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
using ll=long long;
int n,x,tmp;
char ch;
ll ans;
string s;
struct Str{
	ll num;
	char ch;
};
deque<Str> dq;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>x>>ch;
		/*
		if(dq.size() && ch==dq.back().ch) dq.back().num+=x;
		else dq.push_back({x,ch});
		*/
		s+=string(x,ch);
	}
	for(int i=0;i<(int)s.size()/2;++i){
		if(s[i]!=s[s.size()-i-1]) ++ans;
	}
	/*
	for(int i=0,j=dq.size()-1;i<j&&dq.size()>1;){
		if(j>=(int)dq.size()) j=dq.size()-1;
		if((dq[i].num==dq[j].num)&&(dq[i].ch==dq[j].ch)){
			dq.pop_back();
			if(dq.size()) dq.pop_front();
		}else{
			tmp=min(dq[i].num,dq[j].num);
			dq[i].num-=tmp;
			dq[j].num-=tmp;
			if(dq[i].ch!=dq[j].ch) ans+=min(dq[i].num,dq[j].num);
			if(dq[i].num==0) dq.pop_front();
			if(dq[j].num==0) dq.pop_back();
		}
	}
	*/
	cout<<ans;
	
	return 0;
}
