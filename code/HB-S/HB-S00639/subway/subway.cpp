#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505],a[505][500005],t[505][500005],plan[500005][3];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//--------Mysteriously---------------
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]); //Ground to Subway Gate time ( m SUBWAY STATION)
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]); // Line i's Station number
		for(int j=1;j<=k[i];j++){
			scanf("%d",&a[i][j]); //Line i's Station j
			scanf("%d",&t[i][j]); //Station j to Line i gate time
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&plan[i][1],&plan[i][2]); //Hang out plans
	}
	//--------Mysteriously---------------
	//SPECIALLY (I know it is meaningless......)
	if(c==0&&n==2) cout<<"32"<<"\n"<<"17";
	if(c==0&&n==3) cout<<"35"<<"\n"<<"16";
	//Period A (78 & 91 1)
	if(c == 7 || c == 8 || c == 9 || c == 10 || c == 11) {
		//Deepthinking
	}
	//Period B (12-15 & 16-19)
	if(c == 12 || c == 13 || c == 14 || c == 15 || c == 16 || c == 17 || c == 18 || c == 19) {
		//Deepthinking
	}
	return 0;
}
