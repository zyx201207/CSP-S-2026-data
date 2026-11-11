#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],k[501],a[501][500001],t[501][500001],x[100001],y[100001];
int sum(int xi,int yi,int xl,int time){
	int minn = 1000000001;
	for(int i = 0; i < n; i++){
		bool panx = false,pany = false;
		int xp,yp;
		for(int j = 0; j < k[i]; j++){
			if(a[i][j] == xi){
				xp = j;
				panx = true;
			}else if(a[i][j] == yi){
				yp = j;
				pany = true;
			}
		}
		if(panx == true){
			if(pany == true){
				time += t[i][xp];
				time += t[i][yp];
				minn = min(minn,time);
			}else{
				for(int j = 0; j < k[i]; j++){
					if(a[i][j] != xi)minn = min(minn,sum(a[i][j],yi,i,time+t[i][xp]+t[i][j]));
				}
			}
		}
	}
	return minn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int v = 0; v < m; v++){
		cin >> w[v];
	}
	for(int i = 0; i < n; i++){
		cin >> k[i];
		for(int j = 0; j < k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 0; i < q; i++){
		cin >> x[i] >> y[i];
		int minn = 1000000001,xv = x[i],yv = y[i];
	    for(int j = 0; j < n; j++){
		    bool panx = false,pany = false;
		    int xp,yp;
		    for(int h = 0; h < k[j]; h++){
				    if(a[j][h] == x[i]){
					xp = h;
					panx = true;
				}else if(a[j][h] == y[i]){
					yp = h;
					pany = true;
				}
			}
			if(panx == true){
				if(pany == true)minn = min(minn,t[j][xp]+t[j][yp]);
				else{
					for(int h = 0; h < k[j]; h++){
						if(a[j][h] != x[i])minn = min(minn,sum(a[j][h],y[i],j,t[j][xp]+t[j][h]));
					}
				}
			}
		}
		cout << minn+w[xv]+w[yv] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
