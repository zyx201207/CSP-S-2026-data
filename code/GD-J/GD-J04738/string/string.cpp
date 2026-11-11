#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
deque<pair<int,char> >q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		char ch;
		cin>>m>>ch;
		q.push_back({m,ch});
	}
	while(!q.empty()){
		if(q.size()==1)break;
		int a=q.front().first,b=q.back().first;
		char c1=q.front().second,c2=q.back().second;
		q.pop_front();q.pop_back();
		if(c1==c2){
			if(a>b){
				q.push_front({a-b,c1});
			}
			if(b>a){
				q.push_back({b-a,c2});
			}
		}
		else {
			if(a>b){
				ans+=b;
				q.push_front({a-b,c1});
			}
			if(b>a){
				ans+=a;
				q.push_back({b-a,c2});
			}
			if(a==b){
				ans+=a;
			}
		}
	}
	cout<<ans;
	return 0;
}

