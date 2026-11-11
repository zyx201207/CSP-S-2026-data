#include<bits/stdc++.h>
using namespace std;
#define fi first
#define sc second

int n,ans = 0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	deque<pair<long long,char> >q;
	for(int i = 1; i <= n; i++) {
		long long x;
		char y;
		cin>>x>>y;
		q.push_back({x,y});
	}
	while(q.size()){
		long long w1 = q.front().fi,w2 = q.back().fi;
		char c1 = q.front().sc,c2 = q.back().sc;
		q.pop_front();
		q.pop_back();
//		cout<<w1<<c1<<" "<<w2<<c2<<endl;
		long long a;
		if(c1 == c2){
			if(w1 > w2){
				a = w1 - w2;
				q.push_front({a,c1});
			}
			else if(w2 > w1){
				a = w2 - w1;
				q.push_back({a,c1});
			}
		}
		else{
			if(w1 > w2){
				a = w1 - w2;
				q.push_front({a,c1});
				ans+=w2;
			}
			else if(w2 > w1){
				a = w2 - w1;
				q.push_back({a,c2});
				ans+=w1;
			}
			else{
				ans+=w1;	
			} 
		}
	}
	cout<<ans;
	return 0;
}
