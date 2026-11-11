#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int c,n,m,x,y,o,v=1;
int w[N];
int sum,ant;
int b[N][5];
int l;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>x>>y;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int j=1;j<=n;j++){
		cin>>o;
		ant+=o;
		for (;v<=ant;v++){
			b[v][1]=j;
			cin>>b[v][2]>>b[v][3];
		}
	}
	int p,q;
	for (int s=1;s<=y;s++){
		sum=0;
		cin>>p>>q;
		sum+=w[p];
		for (int i=1;i<=ant;i++){
			if(b[i][2]==p){
				sum+=b[i][3];
				l=b[i][1];
				for (int j=1;j<=ant;j++){
					if(b[j][1]==l && b[j][2]==q){
						sum+=b[j][3];
					}
				}
			}
		}
		sum+=w[q];
		cout<<sum<<endl;
	}
	return 0;
}
