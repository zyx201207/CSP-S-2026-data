//GZ-S00444  贵州省松桃民族中学  龙鑫鑫 
#include<bits/stdc++.h>
using namespace std;
struct Sub{
	int zt;
	int time;
}; 
 Sub s[505][505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m];
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	int k;
	 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s[i][j].zt>>s[i][j].time;
		}
	}
	int a[n],b[n];
	int ans[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ans[i]=w[a[i]]+w[b[i]];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(a[i]==s[i][j].zt){
				for(int m=1;m<=k;m++){
					if(b[i]==s[i][m].zt){
						ans[i]=s[i][j].time+s[i][m];
					}
					
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
	return 0;
} 
