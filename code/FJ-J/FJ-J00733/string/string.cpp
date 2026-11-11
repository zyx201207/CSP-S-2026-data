#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll f;
deque<ll>q;
deque<char>r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		char a;
		cin>>a;
		q.push_back(x);
		r.push_back(a);
	}while(!q.empty()){
		if(q.size()==1){
			break;
		}
		if(r.front()==r.back()){
			if(q.front()>q.back()){
				q.front()-=q.back();
				q.pop_back();
				r.pop_back();
			}if(q.front()<q.back()){
				q.back()-=q.front();
				q.pop_front();
				r.pop_front();
			}if(q.front()==q.back()){
				q.pop_front();
				q.pop_back();
				r.pop_front();
				r.pop_back();
			}
		}if(r.front()!=r.back()){
			if(q.front()>q.back()){
				f+=q.back();
				q.front()-=q.back();
				q.pop_back();
				r.pop_back();
			}if(q.front()<q.back()){
				f+=q.front();
				q.back()-=q.front();
				q.pop_front();
				r.pop_front();
			}if(q.front()==q.back()){
				f+=q.front();
				q.pop_front();
				q.pop_back();
				r.pop_front();
				r.pop_back();
			}
		}
	}
	cout<<f;
	return 0;
}
//hello~~~~~

