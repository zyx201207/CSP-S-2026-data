#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+10];
	int x[q+10];
	int y[q+10];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<i+n+2;j++){
			cin>>x[j]>>y[j];
		}
	}
	return 0;
}

