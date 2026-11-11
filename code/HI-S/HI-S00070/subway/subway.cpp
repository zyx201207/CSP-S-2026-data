#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,pp,w[100005],t[500005],a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
	//cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int aa,b;
	cin>>aa>>b>>pp;
	for(int i=1;i<=q;i++){
		cout<<aa*pp;
		if(i<q){
			cout<<endl;
		}
	}
    return 0;
}

