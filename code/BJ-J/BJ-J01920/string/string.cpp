#include<bits/stdc++.h>
using namespace std;
struct node{
	long long ed;char y;
}a[200005];
struct node1{
	long long st;
	long long lo;
	char c;
};
map<long long,node> mp,mp1,mp2;
queue<node1>q;
stack<node1>s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	bool f=0;
	long long cnt=1;
	long long n=0;
	for(int i=1;i<=t;i++){
		cin>>a[i].ed>>a[i].y;
		n+=a[i].ed;
	}
	for(int i=1;i<=t;i++){
		long long k=a[i].ed;
		char x=a[i].y;
		if(cnt-1+k>(n+1)/2){
			long long now=(n+1)/2-cnt+1;
			mp[cnt]={now,x};
			mp1[1]={k-now,x};
			cnt=k-now+1;
			f=1;
		}else if(!f){
			mp[cnt]={k,x};
			cnt+=k;
		}else if(f){
			mp1[cnt]={k,x};
			cnt+=k;
		}
	}
	for(auto i:mp){
		node z=i.second;
		//cout<<i.first<<" "<<z.ed<<"\n";
		q.push({i.first,z.ed,z.y});
	}
	for(auto i:mp1){
		node z=i.second;
		//cout<<i.first<<" "<<z.ed<<"\n";
		s.push({i.first,z.ed,z.y});
	}
	char lx,rx;
	long long ans=0;
	for(int l=1,r=1;!q.empty()&&!s.empty();){
		while(l<r){
			node1 k=q.front();
			q.pop();
			if(l+k.lo<=r){
				ans=ans+(k.c==rx?0:k.lo);
			}else{
				ans=ans+(k.c==rx?0:r-l+1);
			}
			l+=k.lo;
			lx=k.c;
		}
		while(r<l){
			node1 k=s.top();
			s.pop();
			if(r+k.lo<=l){
				ans=ans+(k.c==lx?0:k.lo);
			}else{
				ans=ans+(k.c==lx?0:l-r+1);
			}
			r+=k.lo;
			rx=k.c;
		}
		if(l==r){
			if(!q.empty()){
				node1 k=q.front();
				q.pop();
				l+=k.lo;
				lx=k.c;
			}else if(s.empty()){
				node1 k=s.top();
				s.pop();
				r+=k.lo;
				rx=k.c;
			}
		}
		//cout<<l<<" "<<r;
	}
	cout<<ans;
	return 0;
}
