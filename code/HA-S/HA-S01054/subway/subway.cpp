#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;//amns
int w[50005];//nm
int k[50005],a[5005][5005],t[5005][5005];//nxp 
int x,y;
int ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	//ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(p--){
		cin>>x>>y;
		ans+=(w[x]+w[y]);
		if(c>=7&&c<=11){
			for(int i=1;i<=n;i++){
				ans+=(t[i][1]+t[i][2]);
			}
			cout<<ans<<endl;
		}
		else if(c>=12&&c<=19){
			ans+=t[1][1]*abs(y-x);
			cout<<ans<<endl;
		}
		else{
			cout<<"wcnm"<<endl; 
		}
		
	}
	
	
	return 0;
}


