#include<bits/stdc++.h>
using namespace std;
int a[5005][5005]; //the number of which rail connects i and j(for exchange calculation)
int n,m,d,q;
int thall[500005];
int k[500005];
int t[5005][505]; //time from hall of staion i to rail j platform
int line[505][5005];//Rail No.i goes through No.line[i][j] station
int ans[5005][5005];//shortest time from station i to j

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	//For testcases 1~8 k,m<=400
	while (cin>>c){
		memset(a,0,sizeof(a));
		for (int i=1;i<=5001;i++){
			for (int j=1;j<=5001;j++){
				ans[i][j]=1e9;
			}
		}
		cin>>n>>m>>d>>q;
		for (int i=1;i<=m;i++){
			cin>>thall[i];
		}
		for (int i=1;i<=n;i++){
			cin>>k[i];
			for (int j=1;j<=k[i];j++){
				cin>>line[i][j];
				int tim;
				cin>>tim;
				t[line[i][j]][i]=tim;
				for (int o=1;o<=j;o++){
					a[line[i][o]][line[i][j]]=i;
					a[line[i][j]][line[i][o]]=i;
					ans[line[i][o]][line[i][j]]=t[line[i][o]][i]+t[line[i][j]][i];
					ans[line[i][j]][line[i][o]]=t[line[i][o]][i]+t[line[i][j]][i];
				}
			}
		}
		for (int i=1;i<=m;i++){
			for (int j=1;j<=m;j++){
				for (int o=1;o<=m;o++){
					if (a[i][o]&&a[o][j]&&ans[i][o]-t[o][a[i][o]]+t[o][a[i][o]]+t[o][a[o][j]]+ans[o][j]-t[o][a[o][j]]<ans[i][j]){
						ans[i][j]=ans[i][o]-t[o][a[i][o]]+t[o][a[i][o]]+t[o][a[o][j]]+ans[o][j]-t[o][a[o][j]];
						a[i][j]=a[o][j];
					}
				}
			}
		}
		for (int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<thall[x]+thall[y]+ans[x][y]<<endl;
		}
	}
	return 0;
}
