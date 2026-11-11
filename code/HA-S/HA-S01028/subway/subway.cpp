#include<bits/stdc++.h>
int a[50005][505];//第i个站过得第j个铁道。 
int t[50005][505];
int shu[50005];
int w[50005];
int k[50005];
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//输入
	long long c,n,m,d,q;//n线路,m站点。 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			int stopp,timee;
			cin>>stopp>>timee;
			a[stopp][++shu[stopp]]=i;
			t[stopp][shu[stopp]]=timee;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		bool f=0;
		int min_time=1e9;
		for(int i=1;i<=shu[x];i++){
			for(int j=1;j<=shu[y];j++){
				if(a[x][i]==a[y][j]){
					f=1;
					min_time=min(t[x][i]+t[y][j],min_time);
				}
			}
		}
		if(f==1){
			cout<<w[x]+w[y]+min_time;
		}
		else if(7<=c&&c<=11){
			cout<<w[x]+w[y]+t[x][1]+t[y][1];
		}
	}
	return 0;
}

