#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char zi;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	deque<node> q;
	int n,a1;
	char c1;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a1 >> c1;
		q.push_back({a1,c1});
	}
	long long ans=0;
	while(!q.empty()){
		if(q.size()==1)break;
		int l1=q.front().num;
		int l2=q.back().num;
		char x1=q.front().zi;
		char x2=q.back().zi;
		q.pop_back();
		q.pop_front();
		if(l1>l2){
			if(x1!=x2)ans+=l2;
			q.push_front({l1-l2,x1});
			continue;
		}
		if(l1==l2){
			if(x1!=x2)ans+=l1;
			continue;
		}
		if(l1<l2){
			if(x1!=x2)ans+=l1;
			q.push_back({l2-l1,x2});
		}
	}
	cout << ans;
	return 0;
}

