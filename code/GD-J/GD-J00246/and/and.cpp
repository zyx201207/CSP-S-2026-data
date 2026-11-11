#include<bits/stdc++.h>
using namespace std;
int a[200005],cnt[200005],ans;
int f(int x){
	int cnt=0;
	while(x){
		x/=2;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
    }
	while(m){
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		int c=f(x),d=f(y);
		if(c!=d){
			x-=(1<<c);
			q.push(x);q.push(y);
		}else{
			m-=2;
			if(ans==0)ans=(x&y);
			else ans=ans&(x&y);
		}
	}
	cout<<ans;
	return 0;
} 

