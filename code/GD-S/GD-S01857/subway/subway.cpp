#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000005];
struct node{ 
	int a,t;
}s[1000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s[j].a>>s[j].t;
		}
	}
	for(int i=1;i<=q;i++){
		int x1,y1;
		cin>>x1>>y1;
	}
	return 0;
} 
