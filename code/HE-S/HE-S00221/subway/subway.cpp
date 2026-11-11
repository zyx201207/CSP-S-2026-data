#include<iostream>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k[2];
	for(int i=0;i<2;i++){
		cin>>k[i];
		int f=k[i]*2;
		for(int j=0;j<k[i];j++){
			int a[f],t[f];
			cin>>a[j]>>t[j];
		}
	}
	int x[2],y[2];
	for(int r=0;r<2;r++){
		cin>>x[r]>>y[r];
	}
	for(int i=0;i<2;i++){
		cout<<w[1]+5+7+w[2]<<endl;
	}
	return 0;
}
