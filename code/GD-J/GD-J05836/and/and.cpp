#include <bits/stdc++.h>

using namespace std;

const int N=1000086;

struct sz{
	long long c,d;
	bool operator < (const sz &o) const{
		if(o.d==0){
			return 1;
		}else if(d==0){
			return 0;
		}else if(d!=o.d){
			return d<o.d;
		}else{
			return c<o.c;
		}
	} 
}a[N];

priority_queue<sz> q;
priority_queue<int> p;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n,m,ans=1073741823;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].c;
	}
	for(int i=1;i<=n;i++){
		long long tmp=1;
		for(int j=1;j<=30;j++){
			tmp*=2;
			if(tmp>=a[i].c){
				a[i].d=tmp-a[i].c;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		q.push(a[i]);
	}
	for(int i=1;i<=m-1;i++){
		long long tp;
		tp=q.top().c;
		q.pop();
		ans&=tp;
	}
	long long tm;
	while(q.size()){
		tm=q.top().c;
		p.push(tm);
		q.pop();
	}
	cout<<(ans&p.top())<<"\n";
	return 0;
}
