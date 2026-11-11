#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int A=2e6+6;
ll a[A];
int n;
ll d;
int rt,cnt;
struct S{
	int x;
	ll d;
	friend bool operator < (S x,S y){
		return x.d>y.d;
	}
};

int bfs(int st,int ed){
	cout<<3;
	cout<<1;
	priority_queue<S>q;
	q.push({st,0});
	int mk[A];
	memset(mk,0,sizeof(mk));
	while(!q.empty()){
		int x=q.top().x;
		ll dis=q.top().d;
		q.pop();
		if(x==ed){
			if(!rt)rt=dis;
			else if(rt==dis){
				if(cnt==2)return 1;
				if(cnt>2)return 0;
			}else return 0;
		}//cout<<x<<" "<<dis<<" "<<"\n";
		for(int i=x+1;a[i]-a[x]<=d;i++){
			if(!mk[i]){
				q.push({x,dis+1});
				mk[i]=1;
			}
		}
	}return 0;
}

int main(){
	freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=4;i<=n;i++){
			cout<<1;
			for(int j=1;j<i;j++){
				cout<<2;
				rt=cnt=0;
				ans+=bfs(j,i);
			}
		}cout<<ans;
	}
}
