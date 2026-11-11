#include<bits/stdc++.h>
#define int long long
using namespace std;
struct str{
	int val;
	char c;
}a[200005];
int z[200005];
stack<str> s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,mid=0,midid=0,czn=0,czs=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val>>a[i].c;
		czn+=a[i].val;
		z[i]=czn;
	}
	mid=czn/2+czn%2;
	if(czn%2==0){
		for(midid=1;midid<=n&&z[midid]<=mid;midid++){
			s1.push(a[midid]);
		}
		s1.push({mid-z[midid-1],a[midid].c});
		for(int i=n;i>midid;i--){
			s2.push(a[i]);
		}
		s2.push({z[midid]-mid,a[midid].c});
	}else{
		for(midid=1;midid<=n&&z[midid]<mid;midid++){
			s1.push(a[midid]);
		}
		s1.push({mid-z[midid-1]-1,a[midid].c});
		for(int i=n;i>midid;i--){
			s2.push(a[i]);
		}
		s2.push({z[midid]-mid,a[midid].c});
	}
	while(!s1.empty()&&!s2.empty()){
		str x=s1.top();
		str y=s2.top();
		if(x.c!=y.c){
			if(x.val>y.val){
				czs+=y.val;
				s2.pop();
				s1.top().val-=y.val;
			}else if(x.val==y.val){
				czs+=x.val;
				s1.pop();
				s2.pop();
			}else{
				czs+=x.val;
				s1.pop();
				s2.top().val-=x.val;
			}
		}else{
			if(x.val>y.val){
				s2.pop();
				s1.top().val-=y.val;
			}else if(x.val==y.val){
				s1.pop();
				s2.pop();
			}else{
				s1.pop();
				s2.top().val-=x.val;
			}
		} 
	}
	cout<<czs;
	return 0;
} 
