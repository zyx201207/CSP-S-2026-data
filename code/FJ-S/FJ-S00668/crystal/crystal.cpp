#include<bits/stdc++.h>
using namespace std;
int n,js,nw,ans,y;
priority_queue<long long,vector<long long>,greater<long long> >q;
queue<long long>q1;
long long a,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	y=m;
	for(int i=1;i<=n;i++){
		cin>>a;
		q.push(a);
	}
	while(!q.empty()){
		if(y<q.top()){
			break;
		}
		while(!q1.empty()&&(q.top()-nw)*js>m){
			m+=(nw-q1.front());
			js--;
			q1.pop();
		}
		m-=(q.top()-nw)*js;
		nw=q.top();
		js++;
		ans=max(ans,js);
		q1.push(q.top());
		q.pop();
	}
	cout<<ans;
	return 0;
} 
