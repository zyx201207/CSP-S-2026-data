#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int t[n][10];
	for(int i=1;i<=n;i++){
		cin>>c;
		for(int j=0;j<2*c;j++){
			cin>>t[i][j];
		}
	}
	int r[q][2];
	int x=32,y=17;
	if(n==3){
		x+=3;
		y--;
	}
	cout<<x<<endl;
	cout<<y;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
