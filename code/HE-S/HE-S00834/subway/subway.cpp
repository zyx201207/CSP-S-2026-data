#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long c,n,m,d,q;
	int a[500005],fa[500005];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>a[i];
    		fa[i]=i;
    }
    int z=0;
    long long T;
    while(n--){
    	int k,t,b,c;
    	cin>>k>>b>>t;
    	T=2*t;
    	k-=1;
    	while(k--){
    		cin>>c>>t;
    		fa[c]=b;
		}
	}
	while(q--){
		int d,e;
		cin>>d>>e;
		long long ans=a[d]+a[e];
		ans+=T;
		cout<<ans<<endl;
	}
	return 0;
}
