#include <bits/stdc++.h>
using namespace std;
int dd[5005],liink[205][205];
int main(){
	freopen("r","subway.in",stdin);
	freopen("w","subway.out",stdout);
	int c,n,m,d,q,k,a,t,w[5005],mm[405][205];
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> w[m];
	}
	for (int i=1;i<=n;i++){
		cin >>k;
		for (int j=1;j<=k;j++){
			cin>>a>>t;
			mm[a][j]=t;
			dd[a]++;
			if (dd[a]>=2)
			{
				for (int ii=1;ii<=j;ii++){
					if (mm[a][ii]!=0){
						liink[j][ii]=mm[a][j]+mm[a][ii];
						liink[ii][j]=mm[a][j]+mm[a][ii]; 
						for (int jj=1;jj<=n;jj++){
							if (liink[ii][jj]!=0 && jj!=j && jj!=ii){
								liink[jj][j]=min(liink[jj][j],liink[j][ii]+liink[ii][jj]);
								liink[j][jj]=min(liink[jj][j],liink[j][ii]+liink[ii][jj]);
							}
						}
					}
				}
			}
		}
	}
	int x,y;
	for (int i=1;i<=q;i++){
		cin >> x >> y;
		if (m<=2)
		{
			cout << w[x]+w[y]<< endl;
		}
		else if(true){
    		for (int ii=1;ii<=k;ii++)
	    	{
		    	if (mm[x][ii]!=0 && mm[y][ii]!=0){
		    		cout << w[x]+w[y] << endl;
		    		break;
	    		}
	    	}
	    }
	    else{
	    	int minn=1e9,xx=0;
	    	for (int ii=1;ii<=k;ii++){
	    		for (int j=1;j<=k;j++){
	    			if (liink[ii][j]!=0 && (mm[x][ii]!=0 && mm[y][j]!=0)||(mm[x][j]!=0 && mm[y][ii]!=0)){
		    			cout << w[x]+w[y]+liink[ii][j] << endl;
		    			xx++;
		    			break;
	    			}
	    		}
	    		if (xx!=0)break;
	    	}
	    }
	}
	return 0;
}
