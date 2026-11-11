#include<bits/stdc++.h>
using namespace std;
long long a[100005],a1[1005][1005],b1[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,x,y,l,sum=0;
	int cnt=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>a1[i][j]>>b1[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		sum=0;
		cin>>x>>y;
		sum+=(a[x]+a[y]);
		for(int j=1;j<=n;j++){
			int mm=0,nn=0;
			for(int k=1;k<=n;k++){
			    if(a1[j][k]==x){
			    	mm=1;
				}
				if(a1[j][k]==j){
					nn=1;
				}
		    }
		    if(mm==nn){
		    	cnt=j;
			}
		}
		if(cnt!=0){
			sum+=(b1[cnt][x]+b1[cnt][y]);
		}
		else{
			if(cnt==1){
				sum+=(b1[cnt++][x]+b1[cnt++][y]);
			}
			else{
				sum+=(b1[cnt--][x]+b1[cnt--][y]);
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
