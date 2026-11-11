#include<bits/stdc++.h>
using namespace std;
long long n,T,a,v[200000+5];
deque<long long> q;
deque<long long> p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++) {
		cin>>a;
		p.push_back(a);
	}
	int t=1;
	while(t++<=T){

		for(int i=t-1;i<=n;i++){
			int x=p.front();
			if(v[p.front()]) {
				
				while(!q.empty()&&q.back()!=x) {
					//cout<<q.back()<<" ";
					p.push_back(q.back());
					q.pop_back();
				}
				if(!p.empty()){
					p.push_back(q.back());
					q.pop_back();
					q.push_back(p.front());
					p.pop_front();
					//cout<<q.back()<<" ";
				}
				
			}
			else{
				if(!p.empty()){
					q.push_back(p.front());
					v[x]=1;
					p.pop_front();
				}
			}
			//cout<<q.front()<<" ";
		}
	}
	while(!q.empty()) {
		cout<<q.front()<<" ";
		q.pop_front();
	}
	return 0;
}
