#include<bits/stdc++.h>
using namespace std;
int w[500005],a[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		int k;
		cin>>k;
		for(int i=1;i<=k*2;i++){
			cin>>a[i]>>t[i];
		}
		while(q--){
			int b,e;
			cin>>b>>e;
			cout<<w[b]+t[b]+w[e]+t[e];
		}
		
	return 0;
}
/*
2 3 20 2
4 1 9 
3   1 5/ 2 7 /3 6
1 3
1 2

4+5+6=15
4+5+7=16


*/
