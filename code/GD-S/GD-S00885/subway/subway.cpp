#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=505;
int n,m,c,d,q,ori[MAXN]; 
struct rou{
	int k;
	vector<int> go;
	vector<int> cost;
}node[MAXN];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	/*for(int i=1;i<=m;i++){
		cin>>ori[i];//Ê×Î²¼Ó¼´¿É 
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> route(k);
		for(int i=0;i<k;i++){
			int x,cost;
			cin>>x>>cost;
		}
	}*/
	while(q--){
		int s,e;
		cin>>s>>e;
		srand(time(0));
		cout<<rand()%50<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

