#include<bits/stdc++.h>>
using namespace std;
struct linex{
	int a;
	int ti[505];
	int tj[505];
};
struct startend{
	int xr;
	int yr;
}; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	short int c,n,d;
	int q;
	long long m;
	cin>>c>>n>>m>>d>>q;
	int w[m+5];
	for(int wm=1;wm<=m;wm++){
		cin>>w[wm];
	}
	int k[n+5]={0};
	for(int i=1;i<=n;i++){
		
		cin>>k[i];
		linex linexx[k[i]];
		linexx[i].a=i;//这是第几条线路// 
		for(int j=2;j<=k[i]+1;j++){
			cin>>linexx[i].ti[j]>>linexx[j].tj[j];
		}
	}
	startend se[q+2];
	for(int i=1;i<=q;i++){
		cin>>se[i].xr>>se[i].yr;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[l];l++){
				for(int qqq=1;qqq<=k[i];qqq++){
					for(int www=1;www<=k[l];www++){
						if(linex[j].tj[qqq]==linex[l].tj[www]) int ooo=linex[j].tj[qqq];
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int cnttt=0;
		for(int j=se[i].xr+1;j<se[i].yr-1;j++){
			cnttt=linex[j].tj[ooo];
		}
		cnttt+=w[se[q].xr];
		cnttt+=w[se[q].yr;]
	}

	
	cout<<cnttt;
	
	
	return 0;
} 
