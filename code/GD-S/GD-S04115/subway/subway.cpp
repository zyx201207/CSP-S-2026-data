#include<bits/stdc++.h>
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
	int k[n],a[n][2],t[n][2];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<2;i++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<"0"<<endl;
			break;
		}
		int ans=w[x]+w[y],p=x,check=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<2;k++){
				if(a[j][k]==p){
					ans+=t[j][k]+t[j][i-k];
					if(a[j][1-k]==y){
						cout<<ans;
						check=1;
						break;
					}
					else{
						p=a[j][1-k];
					}
				}
			}
			if(check){
				break;
			}
		}
	}
	return 0;
} 
