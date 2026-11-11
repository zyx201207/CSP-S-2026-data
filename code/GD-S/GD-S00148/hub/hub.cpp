#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define PII pair<ll,ll>
#define pb push_back
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e6+10;
const int INF=0x3f3f3f3f;
ll c,t,u,v,n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		cout<<m-1<<endl;
	}
}

