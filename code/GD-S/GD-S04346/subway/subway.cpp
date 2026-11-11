//subway
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct station{
	//int linecount;
	bool lines[502];
	int line2time[502];
	int intime;
	int exchange=0;
}station[400000];//1 qi shi!!!
struct line{
	//int linecount;
	int exchangestationsindex[400000];
	int exchangestationscount=0;
	int ei_wo_du_dao_na_le=0;
	bool visitedexi[400000];
}line[502];//1 qi shi!!!


int find(int lne,int exii,int lkf){
	int ans=INT_MAX;
	if(station[lkf].lines[lne]) return station[lkf].line2time[lne];
	if(line[lne].visitedexi[exii]) return 2e9;
	if(line[lne].exchangestationsindex[exii+1]<=line[lne].exchangestationscount) ans=min(ans,find(lne,line[lne].exchangestationsindex[exii+1],lkf));
	for(int i=lne;i<=n;i++){
		if(station[line[lne].exchangestationsindex[exii]].lines[i]==true){
			ans=min(ans,find(i,0,lkf));
			break;
		}
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	//int t1,t2;
	for(int i=1;i<=m;i++){//lu zhan
		cin >> station[i].intime;
	}
	for(int i=1;i<=n;i++){//lu xian
		int k;
		cin >> k;
		for(int j=1;j<k;j++){
			int t1,t2;
			cin >> t1 >> t2;
			station[t1].exchange++;
			station[t1].lines[i]=true;
			station[t1].line2time[i]=t2;
			if(station[t1].exchange>1){
				if(station[t1].exchange==2){for(int l=1;l<=i;l++){
					if(station[t1].lines[l]==true){
						line[l].exchangestationsindex[++line[l].exchangestationscount]=t1;
						break;
					}
				}}
				line[i].exchangestationsindex[++line[i].exchangestationscount]=t1;
			}
		}
	}
	for(int i=0;i<=q;i++){
		for (int j=0;j<400000;j++){for(int k=0;k<502;k++){
			line[k].visitedexi[j]=false;
		}}
		int b,e,ans=INT_MAX;
		cin >> b >> e;
		int finans=station[b].intime+station[e].intime;
		for(int j=0;j<n;j++){
			if(station[b].lines[j]!=true) continue;
			ans=min(find(j,0,e),ans);
		}
		finans+=ans;
		cout << finans << endl;
	}
}






















	
