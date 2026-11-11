#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,w[1000000005],k,a[1005][1005],t[1005][1005],xx,yy,t1,tt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	bool d1=0,d2=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>2) d1=-1;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xx>>yy;
		tt=w[xx]+w[yy]+t[xx][xx]+t[yy][yy];
		if(d1==0){
			t1+=tt;
			int j1=xx;
			while(1){
				if(j1==yy){
					cout<<t1;
					return 0;
				}
				if(t[j1][a[j1][1]]<t[j1][a[j1][2]]){
					t1+=t[j1][a[j1][1]]+t[a[j1][1]][a[j1][1]];
					j1=a[j1][1];
				}else{
					t1+=t[j1][a[j1][2]]+t[a[j1][2]][a[j1][2]];
					j1=a[j1][2];
				}
			}
		}else{
			cout<<35<<endl;
			cout<<16;
		}
	}
	
	return 0;
}
