#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500];
struct P{
	int zhan;
	int time;
}a[500][500];
struct Q{
	int qi;
	int zhong;
	int sj;
}b[500];
int k[500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j].zhan>>a[i][j].time;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>b[i].qi>>b[i].zhong;
	}//cin over
	for(int x=1;x<=q;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				for(int g=1;g<=k[i];j++){
					if(a[i][j].zhan==b[x].qi&&a[i][g].zhan==b[x].zhong){
						b[x].sj=w[b[x].qi]+a[i][j].time+a[i][g].time;
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		cout<<b[i].sj<<endl;
	}
	return 0;
}
