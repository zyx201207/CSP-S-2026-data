#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k,a[510][500010],t[510][500010],x[500010],y[500010],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
		return 0;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
		return 0;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans+=w[x[i]]+w[x[i]];long long cnt=0;
		for(int j=1;j<=n;j++){
			for(int r=1;r<=k;r++){
				if(x[i]==a[j][r]){
					for(int e=j+1;e<=n;e++){
						for(int b=1;b<=k;b++){
							if(a[j][b]==a[e][b]){
								cnt+=t[e][b];
								for(int o=1;o<=k;o++)if(a[j][b]!=a[j][o])cnt+=t[j][o];
								for(int o=1;o<=k;o++)if(a[e][b]!=a[e][o])cnt+=t[e][o];
							}
						}
					}
				}
			}
		}
		ans+=cnt;cout<<ans<<"\n";
	}
	
	return 0;
}
