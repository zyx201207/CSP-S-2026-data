#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt,ans;
priority_queue<int> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		q.push(x);
	}cnt=1,ans=q.top();
	q.pop();
	while(cnt!=m){
		cnt++;
		ans=ans&q.top();
		q.pop();
	}cout<<ans;
	return 0;
}
