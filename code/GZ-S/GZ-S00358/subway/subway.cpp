//GZ-S00358   遵义市第四初级中学  何雨泽
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c_CSD,n_XLS,m_ZTS,d_ZDXL,q_CXJH;
	cin>>c_CSD>>n_XLS>>m_ZTS>>d_ZDXL>>q_CXJH;
	int KtoT[m_ZTS+1]={};
	for(int i=1;i<=m_ZTS;i++){
		cin>>KtoT[i];
	}
	int k_XLZS[n_XLS+1][d_ZDXL+2]={};
	for(int i=1;i<=n_XLS;i++){
		cin>>k_XLZS[i][0];
		for(int j=1;j<=k_XLZS[i][0]*2;j+=2){
			cin>>k_XLZS[i][j]>>k_XLZS[i][j+1];
		}
	}
	for(int q=1;q<=q_CXJH;q++){
		int T=0;
		int fZ,tZ;
		cin>>fZ>>tZ;
		T=KtoT[fZ]+KtoT[tZ];
		bool p=0;
		int i=1;
		while(p==0){
			int t=INT_MAX;
			bool q=0;
			for(int j=1;j<=k_XLZS[i][0]*2;j+=2){
				if(q==0&&k_XLZS[i][j]==fZ){
					T+=k_XLZS[i][j+1];
					q=1;
					j=1;
				}
				else{
					if(k_XLZS[i][j]==tZ){
						T+=k_XLZS[i][j+1];
						p=1;
						break;
					}
					else{
						if(k_XLZS[i][j+1]<t&&k_XLZS[i][j]!=fZ){
							t=k_XLZS[i][j+1];
							fZ=k_XLZS[i][j];
						}
				}
				}
			}
			if(p==1){
				break;
			}
			i++;
			if(t<INT_MAX){
				T+=t;
			}
		}
		cout<<T<<endl;
	}
	return 0;
}
