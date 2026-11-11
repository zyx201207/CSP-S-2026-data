//遵义航天高级中学 赵奕钦 考号GZ-S00280 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,as=0;
	cin>>n>>m;	
	int a[n+5],b[n+5][m+5],p[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b[i][j]=a[i]-a[j];						
		}		
		for(int j=0;j<n;j++){
			if(b[i][j]>=0){			
				p[j]=b[i][j];
			}
			else{
				p[j]=100000000000;
			}												
		}
		for(int o=0;o<n;o++){		
			for(int u=0;u<n;u++){
				if(p[u]>p[u+1]){
					int y;
					y=p[u+1];
					p[u+1]=p[u];
					p[u]=y;
				}				
			}
		}
		int cnt=0;
		for(int o=0;o<n;o++){
			int t=m;
			if(t-p[o]>=0){
				cnt++;
				t-=m;
			}
			as=max(as,cnt);			
		}								
	}
		cout<<as;		
	return 0;
}
