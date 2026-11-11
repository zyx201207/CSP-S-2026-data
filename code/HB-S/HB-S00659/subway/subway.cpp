#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
struct node{
	int sta,num[500005],tim[500005];
}l[505];
int r[100005][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l[i].sta;
		for(int j=1;j<=l[i].sta;j++){
			cin>>l[i].num[j]>>l[i].tim[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i][0]>>r[i][1];
	}
	return 0;
}
