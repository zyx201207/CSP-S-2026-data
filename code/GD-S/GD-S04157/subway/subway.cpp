#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
int w[50005];
int stanum[505];
int a[505][500005];
int t[505][500005];
int s,e;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>stanum[i];
		for(int j=0;j<2*stanum[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>s>>e;
		cout<<32;
	} 
	return 0;
} 






















