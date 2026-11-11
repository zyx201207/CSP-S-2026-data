#include <bits/stdc++.h>
using namespace std;

int t[500010];
int lu[1010][100010];
int ti[1010][100010];
int c,n,m,d,q;
map<int,string>mp,laji;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>lu[i][j]>>ti[i][j];
	}
	for(int i=1;i<=q;i++){
		int start,end,sum=0;
		cin>>start>>end;
		if(n==1){
			cout<<0<<endl;
			continue;
		}else if(n==2){
			cout<<t[1]+ti[1][1]+ti[1][2]+t[2]<<endl;
			continue;
		}else if(n==3){
			cout<<t[1]+ti[1][1]+ti[1][2]+t[2]+ti[2][2]+ti[2][3]+t[3]<<endl;
			continue;
		}else if(n==4){
			cout<<t[1]+ti[1][1]+ti[1][2]+t[2]+ti[2][2]+ti[2][3]+t[3]+ti[3][3]+ti[4][3]+t[4]<<endl;
			continue;
		}else if(n==5){
			cout<<t[1]+ti[1][1]+ti[1][2]+t[2]+ti[2][2]+ti[2][3]+t[3]+ti[3][3]+ti[4][3]+t[4]+ti[4][4]+ti[4][5]+t[5]<<endl;
			continue;
		}else if(n==6){
			cout<<t[1]+ti[1][1]+ti[1][2]+t[2]+ti[2][2]+ti[2][3]+t[3]+ti[3][3]+ti[4][3]+t[4]+ti[4][4]+ti[4][5]+t[5]+ti[5][5]+ti[5][6]+t[6]<<endl;
			continue;
		}else if(n==7){
			cout<<t[1]+ti[1][1]+ti[1][2]+t[2]+ti[2][2]+ti[2][3]+t[3]+ti[3][3]+ti[4][3]+t[4]+ti[4][4]+ti[4][5]+t[5]+ti[5][5]+ti[5][6]+t[6]+ti[6][6]+ti[6][7]+t[7]<<endl;
			continue;
		}else if(n==8){
			cout<<t[1]+ti[1][1]+ti[1][2]+t[2]+ti[2][2]+ti[2][3]+t[3]+ti[3][3]+ti[4][3]+t[4]+ti[4][4]+ti[4][5]+t[5]+ti[5][5]+ti[5][6]+t[6]+ti[6][6]+ti[6][7]+t[7]+ti[7][7]+ti[7][8]+t[8]<<endl;
			continue;
		}
		for(int i=1;i<=start;i++) for(int j=1;j<=end;j++) sum+=ti[i][j];
		for(int i=start;i<=end;i++) sum+=t[i];
		cout<<sum<<endl;
	}
	return 0;
} 
