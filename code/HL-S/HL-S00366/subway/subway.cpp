#include<bits/stdc++.h>

using namespace std;
int c,n,m,d,q;
int w[500005],k[500005],a[50005][50005];
int x[500005],y[500005],t[500005][500005];
int l_min=114514,p1=0;
int main(){
	cout<<"hello world!";
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	
	cin>>c>>n>>m>>d>>q;
	for (int i=0;i<m;i++){
		cin>>w[i];
	}
	for (int i=0;i<n;i++){
		cin>>k[i];
		for (int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	for (int r=0;r<q;r++){
		cin>>x[r]>>y[r];
	}
	cout<<"Everything is Over...";
}
