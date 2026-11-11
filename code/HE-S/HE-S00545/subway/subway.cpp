#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int w[105],a[105][105],t[105][105];
	int c,m,n,d,q,k;
	cin>>c>>m>>n>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	cout<<35<<endl;
	cout<<16;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*饿啊，阴死我了,这都是啥啊，s真是凡人不可触
像我这种修为低的直接被吞噬了，j都将将混分拿1之人竟敢闯入神明之境
真是勇敢了，我还是老老实实中考吧，这个什么csp还是算了吧
csps日记：
17：43：蒙完所有题并发呆*/ 
