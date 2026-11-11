//GZ-S00144 贵阳市南明区李端棻中学 周熙沅
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+5];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k[n+5];
	int a[n+5][m+5];
	int t[n+5][m+5];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x[q+5];
	int y[q+5];
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i1=0;i1<q;i1++){
		int cnt=0;
		int z=0;
		int x1,y1,z1;
		for(int i2=0;i2<n;i2++){
			for(int i3=0;i3<k[i2];i3++){
				if(z==0&&x[i1]==a[i2][i3]){
					cnt+=w[a[i2][i3]]+t[i2][i3];
					z=1;
					x1=i2;
				}
				if(z==1&&y[i1]==a[i2][i3]){
					cnt+=w[a[i2][i3]]+t[i2][i3];
					z=2;
					y1=i2;
				}
				if(z==2&&x1!=y1){
					for(int i4=0;i4<k[x1];i4++){
						for(int i5=0;i5<k[y1];i5++){
							if(a[x1][i4]==a[y1][i5]){
								z1=a[x1][i4];
							}
						}
					}
					cnt+=t[x1][z1]+t[y1][z1];
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
