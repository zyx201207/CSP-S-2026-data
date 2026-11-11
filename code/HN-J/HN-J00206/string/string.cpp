#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x;
	char c;
};
int n,sum=0;
string s;
int a[200005];
char c[200005];
deque<node>q;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n;i++){
		int x;
		char c;
		cin>>x>>c;
		q.push_back({x,c});
	}
	while(q.size()>1){
		int x=q.front().x;
		char c=q.front().c;
		int x2=q.back().x;
		char c2=q.back().c;
		q.pop_front();
		q.pop_back();
		if(c==c2){
			if(x<x2){
				x2-=x;
				q.push_back({x2,c2});
			}else if(x>x2){
				x-=x2;
				q.push_front({x,c});
			}
		}else{
			if(x<x2){
				x2-=x;
				sum+=x;
				q.push_back({x2,c2});
			}else if(x>x2){
				x-=x2;
				sum+=x2;
				q.push_front({x,c});
			}else if(x==x2){
				sum+=x;
			}
		}
	}
	cout<<sum;
	return 0;
}
