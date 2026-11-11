//GZ-S00344 贵阳市第九中学 张修涵 
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,qw,ew;
int q,qi[10000][10000],zhong[10000][10000],kouti[10000000],zongzhan,zhanshu[10000][10000],tiche[10000][10000],cnt[10000][10000],pop,ui,chang1,chang2,uie;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>kouti[i];
	}
	for(int i=1;i<=n;i++){
		cin>>zongzhan;
		for(int j=1;j<=2*zongzhan;j++){
			chang1=(j-1)/2;
			chang2=j/2;
			cin>>zhanshu[i][chang2]>>tiche[i][chang1];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qi[i][0]>>zhong[i][0];
	}
	if(c>=7 and c<=11 ){
		for(int i=1;i<=q;i++){
			ui=0;
			for(int j=1;j<=n;j++){
				for(int q=1;q<=zongzhan;q++){
					if(qi[i][0]==zhanshu[j][q]){
						pop=0;
					
				
							if(zhong[i][0]==zhanshu[j][q-1]){
								pop+=tiche[j][q]+tiche[j][q-1];
								ui++;
							}  
							if(zhong[i][0]==zhanshu[j][q+1]){
								pop+=tiche[j][q]+tiche[j][q+1];
								ui++;
							}
						cnt[i][ui]=kouti[qi[i][0]]+kouti[zhong[i][0]]+pop;
						uie++;
					}
				}
				
			}
			uie+=10;
			for(int po=1;po<=uie;po++){
				for(int oi=i+1;oi<=uie;oi++){
					if(cnt[po]>cnt[oi]){
						qw=cnt[i][po];
						ew=cnt[i][oi];
						cnt[i][po]=ew;
						cnt[i][oi]=qw;
						
					}
				}
						
			}
			cout<<cnt[1];
		}
	}

	return 0;
}
