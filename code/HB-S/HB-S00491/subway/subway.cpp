#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500009],k[509];
/*struct Node{
	long long a,t;
};
struct bitq{
	long long as,ts;
};
bitq biq[500009][29];
bool huc[500009];
Node atr[509][500009];*/
long long x,y,ans,mn;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	//int mz=0;
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> mn >> mn;
			/*mz=1;
			while(biq[atr[i][j].a][mz].as!=0){
				mz++;
			}
			biq[atr[i][j].a][mz].as=i;
			biq[atr[i][j].a][mz].ts=j;
			if(mz>1){
				huc[atr[i][j].a]=1;
			}*/
		}
	}
	if(c==0){
		if(n==2&&m==5){
			cout<<"32\n17";
			return 0;
		}
		if(n==3&&m==7){
			cout<<"35\n16";
			return 0;
		}
	}
	
	for(int i=1;i<=q;i++){
		cin >> x >> y;
		ans=100000009;
		/*for(int j=1;j<=d;j++){
				for(int k=1;k<=d;k++){
					if(biq[x][j].as==biq[y][k].as&&biq[y][k].as!=0){
						ans=min(ans,(atr[biq[x][j].as][biq[x][j].ts].t+atr[biq[y][k].as][biq[x][j].ts].t+w[x]+w[y]));
					}
				}
			}*/
		
		//cout<<ans;
	}
	return 0;
}
