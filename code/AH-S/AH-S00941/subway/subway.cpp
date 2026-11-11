#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,s[500100],v[500100],t[500100],r,f,cnt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i];
		for(int j=1;j<=s[i];j++){
			cin>>v[i]>>t[i];
			cnt+=t[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r>>f;
		cout<<cnt;
	}
	return 0;
}
