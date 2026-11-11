#include<bits/stdc++.h>
using namespace std;

struct node{
	long long num;
	char c;	
}a[200005];

long long n,tot;
vector<node> L,R;
stack<node> l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].num>>a[i].c;
		tot+=a[i].num;
	}
	long long t=0,f=0;
	for(int i=1;i<=n;++i){
		t+=a[i].num;
		if(t >= tot/2){
			if(f == 0){
				if(t-tot/2 == 0){
					L.push_back({a[i].num,a[i].c});
				}else{
					L.push_back({a[i].num-t+tot/2,a[i].c});
					R.push_back({t-tot/2,a[i].c});
				}
				f=1;
			}else{
				R.push_back({a[i].num,a[i].c});	
			}
			
		}else{
			L.push_back({a[i].num,a[i].c});
		}
	}
	if(tot%2 == 1){
		R[0].num--;
	}
	for(int i=L.size()-1;i>=0;--i){
		l.push({L[i].num,L[i].c});
	}
	for(int i=0;i<R.size();++i){
		if(R[i].num != 0){
			r.push({R[i].num,R[i].c});
		}
	}
	long long ans=0;
	while(!l.empty() and !r.empty()){
		node x=l.top();
		l.pop();
		node y=r.top();
		r.pop();
		if(x.c != y.c){
			ans += min(x.num,y.num);
		}
		long long m = min(x.num,y.num);
		x.num -= m;
		y.num -= m;
		if(x.num != 0){
			l.push(x);
		}
		if(y.num != 0){
			r.push(y);
		}
	}
	cout<<ans;
	return 0;
}
