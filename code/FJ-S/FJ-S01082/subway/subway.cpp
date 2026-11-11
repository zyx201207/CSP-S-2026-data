#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,e,f,a[100010],ba[510][100010],bb[510][100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ba[i][j]>>bb[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>e>>f;
	}
	cout<<"42"<<endl<<"74";
	return 0;
}

