#include <bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int a;
	char c;
};
queue<st> q;stack<st> s;
signed main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		st tmp;
		cin>>tmp.a>>tmp.c;
		q.push(tmp);
		s.push(tmp);
	}
	while(!q.empty()){
		st a=q.front(),b=s.top();
		if(a.a>b.a){
			q.front().a-=b.a;
			if(a.c!=b.c)ans+=b.a;
			s.pop();
		}
		if(a.a<b.a){
			s.top().a-=a.a;
			if(a.c!=b.c)ans+=a.a;
			q.pop();
		}
		if(a.a==b.a){
			if(a.c!=b.c)ans+=a.a;
			q.pop();
			s.pop();
		}
	}
	cout<<ans/2;
	return 0;
}
