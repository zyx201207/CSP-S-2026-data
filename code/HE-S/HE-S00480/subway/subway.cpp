#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100100];
int k[101000];
vector<int> a[1000];
vector<int> t[1000];
int f[1000][1000];
struct S{
	int x,y;
}s[101000];

void read(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int lsa,lst;
			cin>>lsa>>lst;
			a[i].push_back(lsa);
			t[i].push_back(lst);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s[i].x>>s[i].y;
	}
	
}
void work(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			f[i][a[i][j]]=t[i][i]+t[i][j];
		}	
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read();
	work();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) cout<<f[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
