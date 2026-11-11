#include<bits/stdc++.h>
using namespace std;
const int ma=5e5+5;
const int am=3e5+5;
long long m,n,c,d,q;
long long ans;
int w[ma],k,t[ma];
int kk[ma];
struct node{
	int val,t[133342];
};

int a[ma];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//m站数n线数 w口>厅  t厅>站台 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	vector<int>dk[am][d];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j].val>>a[j].t[j];
			if(kk[j]==0)kk[j]=k;//节点是哪条线的 
			else{//line X
				dk[k].push_back(j);
				if(kk[j]!=-1)dk[kk[j]].push_back(j);
				kk[j]=-1;
				
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		ans=0;
		cin>>x>>y;
		ans=(w[x]+w[y]);
		f(x,y);
		cout<<ans<<"\n";
	}
	
}
