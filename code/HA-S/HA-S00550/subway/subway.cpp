#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,k;
int m_[1000];
int k_[505][500005],t_[505][500005];
int r_[500005][5];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>m_[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>k_[i][j]>>t_[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>r_[r][1]>>r_[r][2];
	}
	while(q--){
		cout<<k_[q][q]<<endl<<t_[q][q]; 
	}
	
	return 0;
} 
