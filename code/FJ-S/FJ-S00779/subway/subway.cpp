#include<bits/stdc++.h>
using namespace std;
int w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];	
	}
	for(int i=1;i<=p;i++){
		int s,e;
		cin>>s>>e;
		cout<<w[s]+w[e]+10<<endl;
	}
	return 0;
}
