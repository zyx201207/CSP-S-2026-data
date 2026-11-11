#include<bits/stdc++.h> 
using namespace std;
int c;//测试点编号 若 c = 0，则该测试点为样例。
int n;//地铁线路数 
int m;//地铁站数  
int d;//每个地铁站最多被几条线路经过 
int q;//出行计划数 
int w[500009];
long long a[5009][5009],t[5009][5009],minn;
long long d1[50009],x[50009],y[10009],num[50009],ztime[5000009];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
		d1[i]=d;
	}
	for(int i=0;i<n;i++){
		cin>>num[i];
		for(int j=0;j<num[i];j++){
			cin >> a[i][j] >> t[i][j];
			
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<q;i++){
	   
	    for(int k=0;k<50009;k++){
		
			for(int j=0;j<n;j++){
			if(a[j][k]==x[i]){
				minn+=w[x[i-1]]+t[j-1][k];
			}
			if(a[j][k]==y[i]){
				minn+=t[j-1][k]+w[y[i-1]];
				
			}
		}
		
	}
	cout<<minn<<endl;
	minn=0;
}
return 0;
}

