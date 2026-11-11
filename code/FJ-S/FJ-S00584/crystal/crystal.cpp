#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
const int N=5e5+5;
struct node{
	int id,diff;
	bool operator<(const node&other)const{
		if(diff==other.diff)return id<other.id;
		return diff>other.diff;
	}
};
priority_queue<node> q;
int a[N],d[N],mx=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=abs(a[i-1]-a[i]);
	}
	for(int i=1;i<=n;i++){
		q.push({i,d[i]});
	}
	int cnt=1,tot=0;
	while(tot<=m){
		tot+=cnt*q.top().diff;
		cnt++;
		q.pop();
	}
	cout<<cnt-1<<endl;
	return 0;
}
