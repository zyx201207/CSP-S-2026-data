#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0x3f3f3f3f;
priority_queue<int,vector<int> >q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		q.push(a);
	}
	for(int i=1;i<=m;i++)ans&=q.top(),q.pop();
	cout<<ans<<'\n';
	return 0;
}
