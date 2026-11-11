#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x[500500],y[500500];
int k[501][500050],t[501][500500],minn,da[500500],w[100001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i][0];
		for(int j=1;j<=k[i][0];j++){
			cin>>k[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			for(int l=i;l<=k[j][0];l++){
				if(k[j][l]==y[i])
				  da[y[i]]=t[j][l];
			}
		}
		for(int i=1;i<=500500;i++){
			da[i]=100000000;
		}
		while(da[x[i]]>9999999){
			for(int j=1;j<=n;j++){
				minn=199999999;
				for(int o=1;o<=k[j][0];o++)
					minn=min(minn,da[k[j][o]]);
				for(int o=1;o<=k[j][0];o++)
					da[k[j][o]]=min(minn+t[j][o]+w[k[j][o]],da[k[j][o]]);
			}
		}
		cout<<da[x[i]]<<endl;
	}
	return 0;
}
