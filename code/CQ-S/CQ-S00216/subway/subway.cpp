#include<bits/stdc++.h> 
using namespace std;
struct ji{
	int s,e;
};
ji z[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[50005],k[505],a[505][50005],t[505][50005],ans=0,j[50005]={};
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		j[k[i]]++;
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>z[i].s>>z[i].e;
		ans+=w[z[i].s]+w[z[i].e];
		for(int j=z[i].s;j<z[i].e;j++){
			ans+=t[j][j]+t[j][j+1];
		}
	}
	cout<<ans;
	return 0;
}
