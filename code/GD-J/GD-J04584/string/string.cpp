#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define filename "string"
const int N=2*1e5+5;
int n,last=0;
bool flag=0;
int ans=0;
int cnt=0;
struct node{
	int ll,rr;
	char c;
	bool operator<(node b)const{
		return ll>b.ll;
	}
};
queue<node>q1;
priority_queue<node>qa,qb;
signed main(){
	fastio;
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		int l,r;
		cin>>l>>c;
		r=last+l;
		l=last+1;
		last=r;
		q1.push({l,r,c});
//		cout<<l<<' '<<r<<endl;
		cnt+=l-r+1;
	}
	int mid=last/2+last%2;
//	cout<<mid;
	while(!q1.empty()){
		int l=q1.front().ll,r=q1.front().rr;
		char c=q1.front().c;
		q1.pop();
		if(last%2){
//			cout<<'z';
			if(l<=mid&&r>=mid){
//				cout<<'x';
				if(l!=r){
					qa.push({l,mid-1,c});
//					cout<<"qa"<<l<<' '<<mid-1<<endl;
					qb.push({last-r+1,last-mid,c});
					continue;
				}
			}
		}else{
			if(l<=mid&&r>=mid+1){
				qa.push({l,mid,c});
//				cout<<"qa"<<l<<' '<<mid-1<<endl;
				qb.push({last-r+1,last-mid,c});
				continue;
			}
		}
//		cout<<flag<<endl;
//		cout<<l<<' '<<r<<endl;
		if(last%2){
			if(r<mid){
				qa.push({l,r,c});
//				cout<<"qa"<<l<<' '<<r<<endl;
			}else if(l>mid){
				qb.push({last-r+1,last-l+1,c});
//				cout<<"qb"<<last-r+1<<' '<<last-l+1<<endl;
			}
		}else{
			if(r<=mid){
				qa.push({l,r,c});
//				cout<<"qa"<<l<<' '<<r<<endl;
			}else{
				qb.push({last-r+1,last-l+1,c});
//				cout<<"qb"<<last-r+1<<' '<<last-l+1<<endl;
			}
		}
	}
	while(!qa.empty()&&!qb.empty()){
		int l1=qa.top().ll,r1=qa.top().rr;
		int l2=qb.top().ll,r2=qb.top().rr;
		char c1=qa.top().c,c2=qb.top().c;
		qa.pop();
		qb.pop();
//		cout<<"ok";
//		cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
		if(r2>r1){
			if(c1==c2){
				qb.push({r1+1,r2,c1});
			}else{
				ans+=min(r1-l1+1,r2-l2+1);
				qb.push({r1+1,r2,c2});
			}
		}else if(r2<r1){
			if(c1==c2){
				qa.push({r2+1,r1,c1});
			}else{
				ans+=min(r1-l1+1,r2-l2+1);
				qa.push({r2+1,r1,c1});
			}
		}else{
			if(c1!=c2){
				ans+=min(r1-l1+1,r2-l2+1);
			}
		}
	}
	cout<<ans;
}
