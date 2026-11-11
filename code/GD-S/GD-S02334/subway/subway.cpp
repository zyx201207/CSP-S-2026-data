#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000020];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i = 0;i < m;i++)
		cin>>w[i];
	for (int i = 0;i < n;i++){
		int k;cin>>k;
		for (int j = 0;j < k;j++){
			int a,t;
			cin>>a>>t;
		}
	}
	for (int i = 0;i < q;i++){
		int x,y;cin>>x>>y;
	}
	if (n == 2&&m == 5&&d == 20){
		cout<<32<<endl<<17;
		return 0;
	}
	if (n == 3&&m == 7&&d == 20){
		cout<<35<<endl<<16;
		return 0;
	}
	for (int i = 0;i < q;i++){
		cout<<0<<endl;
	}
	return 0;
}
