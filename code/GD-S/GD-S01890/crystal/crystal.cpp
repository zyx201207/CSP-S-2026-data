#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll m;
int n;
vector<ll>s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	s.resize(n,0);
	priority_queue<ll,vector<ll>,greater<ll>>q;
	for(int i=0;i<n;i++){
		cin>>s[i];
		q.push(s[i]);
	}
	
	while(m--){
		//sort(s.begin(),s.end());
		ll a=q.top();
		q.pop();
		a+=1;
		q.push(a);
		
	}
	//sort(s.begin(),s.end());
	for(int i=0;i<n;i++){
		if(q.empty())break;
		s[i]=q.top();
		q.pop();

	}
//	for(int i=0;i<n;i++){
//		q.push(s[i]);
//	}
	
	ll maxx=0;
		ll cnt=1;
		for(int i=1;i<s.size()-1;i++){
			
				if(s[i]==s[i-1]){
					cnt++;
					if(cnt>maxx){
						maxx=cnt;
					}
				}else{
					cnt=1;
				}
			
		}
		cout<<maxx;
	return 0;
}

