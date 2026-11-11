#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;ll cnt=0,ans=0;
	queue<pair<int,char> >a;
	stack<pair<int,char> >s;
	for(int i=1;i<=n;i++){
		int n;char ch;cin>>n>>ch;
		a.push({n,ch}); 
		cnt+=n;
	}
	cnt=(int)ceil(1.0*cnt/2);bool f=cnt%2;
	while(cnt){
		if(cnt-a.front().first>0){
			cnt-=a.front().first,s.push(a.front()),a.pop();
		}else{
			a.front().first-=cnt,cnt=0;
			s.push({a.front().first,a.front().second});
		}
	}
	while(!s.empty()){
		ll tmp=0,d=0;
		while(tmp<s.top().first){
			if(s.top().second==a.front().second)d+=s.top().first;
			tmp+=s.top().first;
			if(tmp>s.top().first){
				s.top().first-=s.top().first-tmp;break;
			}s.pop();
		}
		ans+=tmp-d;
	}cout<<ans<<"\n";
	return 0;
} 
