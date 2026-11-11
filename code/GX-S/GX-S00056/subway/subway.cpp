#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct oppo{
	int k,t[25];
	vector<int>a;
	int vis=0;
}ab[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	int w[m+5];
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>ab[i].k;
		for(int j=1;j<=ab[i].k;j++){
			int x,y;
			cin>>x>>y;
			ab[i].a.push_back(x);
			ab[i].t[x]=ab[x].t[i]=y;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(y-x==1)cout<<w[x]+w[y]+ab[x].t[x]<<endl;
		else{
			int cnt=w[x]+w[y]+ab[x].t[x];
			for(int j=x+1;j<=y;j++){
				cnt+=ab[j-1].t[j];
				if(j!=y)cnt+=ab[j].t[j];
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
