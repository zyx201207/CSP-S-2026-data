#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<vector<pair<int,int> > > v;
int w[50005],a[507][50005],t[507][50005];
int vv[1007][1007];
int sh[50005];
priority_queue< pair<int,int> , vector<pair<int,int> > ,greater<pair<int ,int> > > vq;

void AA(){
	for(int i=1;i<=n;i++){
		int aa=a[i][1],bb=a[i][2],l=t[i][1]+t[i][2];
		v[aa].push_back({l,bb});
		v[bb].push_back({l,aa});
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			sh[j]=1e5+5;
		}
		for(int j=1;j<=v[i].size();j++){
			
		}
	}
}


int main(){
	freopen("subway","r",stdin);
	freopen("subway","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bool A=1;
	cout<<'#';
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		if(s!=2){
			A=0;
		}
		for(int j=1;j<=s;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	AA();
} 
