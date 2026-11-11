#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e5+10;
int n,a[MAXN],m;
struct node{
	int v,rl;
	bool operator >(const node& a) const{
		return v<a.v;
	}
};
priority_queue<node,vector<node>,greater<node> > q,eq;
int maxa,cnt;
int ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		eq.push({a[i],a[i]});
	}
	cnt=1;
	while(maxa>=cnt){
		cnt*=2;
	}
	while(cnt!=0){
		cnt/=2;
		//cout<<cnt<<' ';
		while(!eq.empty()){
			node u=eq.top();
//			cout<<u.v-cnt<<','<<u.rl<<' ';
			if(u.v>=cnt){
				q.push({u.v-cnt,u.rl});
				eq.pop();
			}
			else{
				break;
			}
		}
//		cout<<endl;
		if(q.size()==m){
			while(!eq.empty()) eq.pop();
			while(!q.empty()){
				eq.push(q.top());
				q.pop();
			}
			break;
		}
		else if(q.size()>m){
			while(!eq.empty()) eq.pop();
			while(!q.empty()){
				eq.push(q.top());
				q.pop();
			}
		}
		else{
			while(!q.empty()){
				eq.push(q.top());
				q.pop();
			}
		}
	}
	ans=eq.top().rl;
	int idx=0;
	while(idx<m){
//		cout<<eq.top().rl<<' ';
		ans&=eq.top().rl;
		eq.pop();
		idx++;
	}
	cout<<ans<<endl;
	
	return 0;
}
