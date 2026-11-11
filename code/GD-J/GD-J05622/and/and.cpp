#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
queue<int> q,p;
int ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	for(int i=30;i>=0;i--){
		int cnt=0;
		while(q.size()){
			int x=q.front();
			if(x&(1<<i)){
				cnt++;
			}
			q.pop();
			p.push(x);
		}
		while(p.size()){
			q.push(p.front());
			p.pop();
		}
		if(cnt>=m){
			while(q.size()){
				int x=q.front();
				if(x&(1<<i)){
					p.push(x);
				}
				q.pop();
			}			
			while(p.size()){
				q.push(p.front());
				p.pop();
			}	
			ans+=(1<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
