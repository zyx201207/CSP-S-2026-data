#include<bits/stdc++.h>
using namespace std;
int w[500005];//地铁口到站厅时间
int a[500005],t[500005];
int vis[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int T;
	for(int i=1;i<=n;i++){
		int k1;
		cin>>k1;
		for(int j=1;j<=k1;j++){
			cin>>a[j]>>t[j];
			T=t[j];
			vis[a[j]]=i;
		}
	}
	//cout<<T;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int cnt=0;
		if(vis[x]==vis[y]){
			cnt+=w[x]+w[y]+T*2;
		}else{
			cnt+=w[x]+w[y]+T*2;
		}
		cout<<cnt<<endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
