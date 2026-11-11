//GZ-S00172 中央民族大学附属中学贵阳学校 杨忠瀚 
#include<bits/stdc++.h>
using namespace std;
int w[500005];
int a[100005][500],sxl[500005],exl[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int z;
			cin>>z>>a[i][z];
		}
	}
	while(q--){
		long long ans=0;
		int x,y;
		cin>>x>>y;
		int xx,yx;
		for(int i=1;i<=n;i++){
			if(a[i][x])xx=i;
			if(a[i][y])yx=i;
		}
		cout<<a[xx][x]+a[xx][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
