//GZ-S00141 遵义市新蒲中学 王墨霖 
#include<bits/stdc++.h>
using namespace std;
int m1[500005],m2[500005],a[501][500005],t[501][500005],n1[501],r[100005][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>m1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>n1[i];
		for(int j=1;j<=n1[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i][0]>>r[i][1];
		int p1=0,p2=0;
		for(int i=1;i<=n;i++){
		for(int j=1;j<=n1[i];j++){
			if(a[i][j]==r[i][0] && p1==0){
				p1=t[i][j];
			}else if(a[i][j]==r[i][1] && p2==0){
				p2=t[i][j];
			}
			}
		}
		cout<<m1[r[i][0]]+p1+p2+m1[r[i][1]]<<endl;
	}
	return 0;
}
