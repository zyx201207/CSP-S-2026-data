#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
//#define int long long
//#define cerr if(0)clog
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
		}
		cout<<m-1<<'\n';
	}
}
