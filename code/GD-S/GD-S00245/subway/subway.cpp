#include<bits/stdc++.h>
using namespace std; 
const int maxn = 1000005;

int c,n,m,d,q;
int todor[maxn],mas[1005][1005],cntline[505][1005][5];//i,j,1=地铁站，i,j,2是走时 
//1起2终 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(mas,0x3f,sizeof(mas));
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> todor[i];
	}
	for(int i=1;i<=n;i++){
		cin >> cntline[i][0][0];
		for(int j=1;j<=cntline[i][0][0];j++){
			cin >> cntline[i][j][1] >> cntline[i][j][2];
		}
		for(int j=1;j<=cntline[i][0][0];j++){
			for(int k=1;k<=j;k++){
				cntline[j][k][3]=cntline[j][k][2]+cntline[k][j][2];
			}
		}
	}
	
	for(int k=1;k<=1005;k++){
		for(int i=1;i<=1005;i++){
			for(int j=1;j<=1005;j++){
				mas[i][j]=min(mas[i][j],mas[i][k]+mas[k][j]+cntline[i][k][3]+cntline[k][j][3]);
			}
		}
	}
	
	int s,e;
	while(q--){
		cin >> s >> e;
		int ans=todor[s]+todor[e];
		
		ans+=mas[s][e];
		cout << ans << '\n'; 
	}
	
	return 0;
}
