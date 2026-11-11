#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5; 
int n,m,a[N],len,k,g,ans;
priority_queue<int> p;
queue<int> q1,q2;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p.push(a[i]);
	}
	k=p.top();
	while(k!=0){
		k>>=1;
		len++;
	}
	len--;
	g=n;
	for(int i=(1<<len);i>=1;i>>=1){
		int d=g;
		for(int j=1;j<=g;j++){
			int f=p.top();
			p.pop();
			if(f>=i){
				q1.push(f-i);
				q2.push(f-i);
			}
			else{
				q1.push(f);
				d--;
			}
		}
		if(d>=m){
			g=d;
			while(!q1.empty()){
				q1.pop();
			}
			while(!q2.empty()){
				p.push(q2.front());
				q2.pop();
			}
			ans+=i;
		}
		else{
			while(!q1.empty()){
				p.push(q1.front());
				q1.pop();
			}
			while(!q2.empty()){
				q2.pop();
			}
		}
	}
	cout<<ans;
	return 0;
}

