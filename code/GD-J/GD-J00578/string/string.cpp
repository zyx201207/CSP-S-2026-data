#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char c;
};
deque<node> q;
int n;
int x;
char c;
unsigned long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		q.push_front({x,c});
	}
	while(q.size()>1){
		node l=q.front(),r=q.back();
		q.pop_front();
		q.pop_back();
		if(l.c==r.c){
			if(l.x>r.x){
				q.push_front({l.x-r.x,l.c});
			}else if(l.x<r.x){
				q.push_back({r.x-l.x,r.c});
			}
		}else{
			sum+=min(l.x,r.x);
			if(l.x>r.x){
				q.push_front({l.x-r.x,l.c});
			}else if(l.x<r.x){
				q.push_back({r.x-l.x,r.c});
			}
		}
	}
	cout<<sum;
} 
