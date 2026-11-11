#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*
	ll n,sum=0;
	cin>>n;
	stack<pair<ll,char>> v;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		v.push({a,c});
	}
	if(sum%2==0){
		queue<pair<ll,char>> q;
		queue<pair<ll,char>> q2;
		double mid=(sum+1)/2;
		ll u=0;
		while(v.size()){
			if(u+v.top().first<=mid){
				q.push({v.top().first,v.top().second});
				u+=v.top().first;
				v.pop();
			}else if(u+v.top().first>mid&&u>=mid){
				q2.push({v.top().first,v.top().second});
				u+=v.top().first;
				v.pop();
			}else{
				q.push({sum/2-u,v.top().second});
				q2.push({u+v.top().first-sum/2,v.top().second});
				u+=v.top().first;
				v.pop();
			}
		}
		queue<pair<ll,char>> q1;
		while(q.size()){
			q1.push({q.front().first,q.front().second});
			q.pop();
		}
		ll ans=0;
	    while(q1.size()){
	    	int v1=q1.front().first;
	    	while(v1>0){
	    		if(v1-q2.front().first==0){
	    			if(q1.front().second!=q2.front().second){
	    				ans+=q1.front().first;
					}
	    			v1-=q1.front().first;
	    			q1.pop();
	    			q2.pop();
				}else if(v1-q2.front().first<0){
					if(q1.front().second!=q2.front().second){
	    				ans+=q1.front().first;
					}
					v1-=q1.front().first;
					//q1.pop();
					int c=q2.front().first;
					char d=q2.front().second;
					q2.pop();
					q2.push({c-v1,d});
					q1.pop();
				}else if(v1-q2.front().first>0){
					if(q1.front().second!=q2.front().second){
	    				ans+=q2.front().first;
					}
					v1-=q2.front().first;
					q2.pop();
				}
			}
		}
		cout<<ans;
	}
	if(sum%2==1){
		queue<pair<ll,char>> q;
		queue<pair<ll,char>> q2;
		double mid=sum/2;
		ll u=0;
		while(v.size()){
			if(u+v.top().first<=mid){
				q.push({v.top().first,v.top().second});
				u+=v.top().first;
				v.pop();
			}else if(u+v.top().first>mid&&u>=mid){
				q2.push({v.top().first,v.top().second});
				u+=v.top().first;
				v.pop();
			}else{
				q.push({sum/2-u,v.top().second});
				q2.push({u+v.top().first-sum/2,v.top().second});
				u+=v.top().first;
				v.pop();
			}
		}
		queue<pair<ll,char>> q1;
		while(q.size()){
			q1.push({q.front().first,q.front().second});
			q.pop();
		}
		ll ans=0;
	    while(q1.size()){
	    	int v1=q1.front().first;
	    	while(v1>0){
	    		if(v1-q2.front().first==0){
	    			if(q1.front().second!=q2.front().second){
	    				ans+=q1.front().first;
					}
	    			v1-=q1.front().first;
	    			q1.pop();
	    			q2.pop();
				}else if(v1-q2.front().first<0){
					if(q1.front().second!=q2.front().second){
	    				ans+=q1.front().first;
					}
					v1-=q1.front().first;
					//q1.pop();
					int c=q2.front().first;
					char d=q2.front().second;
					q2.pop();
					q2.push({c-v1,d});
					q1.pop();
				}else if(v1-q2.front().first>0){
					if(q1.front().second!=q2.front().second){
	    				ans+=q2.front().first;
					}
					v1-=q2.front().first;
					q2.pop();
				}
			}
		}
		cout<<ans;
	}
	*/
	ll n,sum=0;
	cin>>n;
	deque<pair<ll,char>> v;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		v.push_back({a,c});
	}
	ll ans=0;
	ll l=1,r=n;
	while(l<=r){
				if(v.front().first-v.back().first==0){
	    			if(v.front().second!=v.back().second){
	    				ans+=v.front().first;
					}
	    			v.pop_back();
	    			v.pop_front();
	    			l++;r--;
				}else if(v.front().first-v.back().first<0){
					if(v.front().second!=v.back().second){
	    				ans+=v.front().first;
					}					//q1.pop();
					int c=v.back().first;
					char d=v.back().second;
					v.pop_back();
					v.push_back({c-v.front().first,d});
					v.pop_front();
					l++;
					
				}else if(v.front().first-v.back().first>0){
					if(v.front().second!=v.back().second){
	    				ans+=v.back().first;
					}
					int c=v.front().first;
					char d=v.front().second;
					v.pop_front();
					v.push_front({c-v.back().first,d});
					v.pop_back();
					r--;
				}
	}
	cout<<ans;
}
