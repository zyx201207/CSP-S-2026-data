#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[500005],t[1005][1005],a[1005][1005],tim[1005][1005];
int x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		tim[a[i][1]][a[i][2]]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int s=1;s<=k[i];s++){
				for(int x=1;x<=k[j];x++){
					if(a[i][s]==a[j][x]){
						if(s==1&&x==1){
							tim[a[i][2]][a[j][2]]=t[i][2]+t[j][2];
							tim[a[j][2]][a[i][2]]=t[i][2]+t[j][2];
						}else if(s==2&&x==1){
							tim[a[i][1]][a[j][2]]=t[i][1]+t[j][2];
							tim[a[i][1]][a[j][2]]=t[i][1]+t[j][2];
						}else if(s==2&&x==2){
							tim[a[i][1]][a[j][1]]=t[i][1]+t[j][1];
							tim[a[i][1]][a[j][1]]=t[i][1]+t[j][1];
						}else if(s==1&&x==2){
							tim[a[i][2]][a[j][1]]=t[i][2]+t[j][1];
							tim[a[i][2]][a[j][1]]=t[i][2]+t[j][1];
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=0;
		ans=ans+w[x]+w[y];
		int ans1=99999999999999,ans2=9999999999999999;
		for(int i=1;i<=n;i++){
			if(t[i][x]!=0) ans1=min(ans1,t[i][x]);
		}
		for(int i=1;i<=n;i++){
			if(t[i][y]!=0) ans2=min(ans1,t[i][y]);
		}
		ans=ans1+ans2+w[x]+w[y]+tim[x][y];
		cout<<ans<<"\n";
		}
	return 0;
}
