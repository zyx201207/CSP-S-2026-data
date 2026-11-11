#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2e5+5;
int c,n,m,d,q;
ll a[505][505];
ll dp[505][505];
int w[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	ll len=n+m+1;
	for(int i=1;i<=len+5;++i)
		for(int j=1;j<=len+5;++j){
			a[i][j]=1e17;
			if(i==j) a[i][j]=0;
		}
			
		
		
	for(int i=1;i<=n;++i){
		ll ki;
		cin>>ki;
		for(int j=1;j<=ki;++j){
			ll aij,tij;
			cin>>aij>>tij;
			a[aij][m+i]=tij;
			a[m+i][aij]=tij;
		}
	}

	for(int k=1;k<=len;++k){
		for(int i=1;i<=len;++i){
			for(int j=1;j<=len;++j){
				if(a[i][k]+a[k][j]<a[i][j]){
					a[i][j]=a[i][k]+a[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<a[x][y]+w[x]+w[y];
	}
	return 0;
}
/*This is Pingyin
 * zheshiwozuihouyicicanjiaCSPle(keneng,wode whk binbu good danwoyijiureaizheOI,buzhishihezhongjibanwoyongyuanfangbuxiata,jingganwobinbushiyigechuanyishenzhisuanbushangtianfuyibindeOIer,suoyiyebuguodachuleT1,T2debaolifen.
 * AFOzhiqianyouyixiexingyuan:he Xiaozi_qwq laoshi heyigeying
 * huoxvxiezhiyiqieyebuguoshiweileshangyici GX-CSP-S mihuoxingweidashang,yesuanyingzhenglewodeaimuxvrong
 * My luogu id jiazihan1208&w0_0w
 * 
 * 
 *  */

