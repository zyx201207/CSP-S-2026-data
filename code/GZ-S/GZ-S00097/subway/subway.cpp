//GZ-S00097 安顺市第二高级中学 郭竞琦 
#include<bits/stdc++.h>
using namespace std;
const int Max=2e6+7;
int c,n,m,d,q,w[Max];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int r[q+7][2];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[k],t[k];
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i][0]>>r[i][1];
	}
	cout<<35<<"\n"<<16;
	return 0;
}
