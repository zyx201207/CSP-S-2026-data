#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
typedef pair<int,int> PII;
typedef queue<PII> qe;
map<int,qe>a;
int w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x,z,t;
		cin>>x;
		for(int j=1;j<=x;j++){
			a[i].push(make_pair(z,t));
		}
	}while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
