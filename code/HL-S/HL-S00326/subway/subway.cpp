#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXN=5e5+5;
int w[MAXN];
struct N{
	int a,t;
}lines[501][MAXN/2];

int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i =1;i<=m;i++)cin>>w[i];
	for(int i =1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++)cin>>lines[i][j].a>>lines[i][j].t;
		
	}
	for(int i = 1;i<=q;i++){
		int l,r;cin>>l>>r;
		int ans=w[l]+w[r];
		for(int k = 1;k<=n;k++)
		for(int j = 1;j<=n;j++){
			if(lines[k][j].a==l)ans+=lines[k][j].t;
			if(lines[k][j].a==r)ans+=lines[k][j].t;
		}
		cout<<ans<<endl;
	}return 0;
	
}