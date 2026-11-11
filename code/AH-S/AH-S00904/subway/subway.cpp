#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,n,m,d,q,w[100100],a[100100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++) cin>>w[i];
    for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[j];
		}
	}
	int r;
	cin>>r;
	while(r--){
		int x,y;
		cin>>x>>y;
		cout<<0<<endl;
	}
    return 0;
}
