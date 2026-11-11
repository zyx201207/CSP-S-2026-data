#include<bits/stdc++.h>
using namespace std;

long long n;
deque<pair<long long,char>>q;
long long ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		q.push_back({x,y});
	}
	while(q.size()>1){
		auto t1=q.front();
		auto t2=q.back();
		q.pop_front();
		q.pop_back();
		if(t1.first>t2.first){
			if(t1.second==t2.second){
				q.push_front({t1.first-t2.first,t1.second});
			}
			else{
				q.push_front({t1.first-t2.first,t1.second});
				ans+=t2.first;
			}
		}
		else if(t1.first<t2.first){
			if(t1.second==t2.second){
				q.push_back({t2.first-t1.first,t2.second});
			}
			else{
				q.push_back({t2.first-t1.first,t2.second});
				ans+=t1.first;
			}
		}
		else{
			if(t1.second!=t2.second){
				ans+=t1.first;
			}
		}
	}
	cout<<ans;
	return 0;
}
