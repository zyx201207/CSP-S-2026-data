#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
	int a;
	char c;
}arr[200010];

deque<Node> q;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].a>>arr[i].c;
		q.push_front(arr[i]);
	}
	int ans=0;
	while(!q.empty()){
		int sz=q.size();
		if(sz==1){
			break;
		}
		Node a=q.front();
		Node b=q.back();
		q.pop_front();
		q.pop_back();
		int x=min(a.a,b.a);
		if(a.c!=b.c){
			ans+=x;
		}
		if(a.a>b.a){
			q.push_front({a.a-x,a.c});
		}else if(a.a<b.a){
			q.push_back({b.a-x,b.c});
		}
	}
	cout<<ans;
	return 0;
}

