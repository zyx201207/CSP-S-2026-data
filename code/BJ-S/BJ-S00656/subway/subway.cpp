#include<bits/stdc++.h>
using namespace std;
struct s{
	int a_qd;
	int t_zd;
	int x;
};
int c,n,m,d,q,a[500005],k;
s cc[500][500005],xc[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway,out","r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		//cc[i][0].
		for(int j=1;j<=k;j++){
			cin>>cc[i][j].a_qd>>cc[i][j].t_zd;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xc[i].a_qd>>xc[i].t_zd;
	}
	long long sum;
	for(int i=1;i<=q;i++){
		if(c>=7&&c<=11){
			sum+=a[xc[i].a_qd]+a[xc[i].t_zd];
			for(int j=1;j<=n;j++){
				//for(int l=i;l)
			}
		}
		else if(c>=12&&c<=19){
			sum+=a[xc[i].a_qd]+a[xc[i].t_zd];
		}
		else{
			sum+=a[xc[i].a_qd]+a[xc[i].t_zd];
		}
	}
	return 0;
}
