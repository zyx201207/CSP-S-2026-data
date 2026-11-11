#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int ans=0,n,d,p[100005]={};
		cin>>n>>d;
		for(int j=1;j<=n;j++)	cin>>p[j];
		for(int j=1;j<=n;j++){	
			for(int k=j+1;k<=n;k++){
				int w=0;
				if(d*2>n) w++;
				if(p[k]-p[j]%d==0&&k-j>1) w++;
				if((p[k]-p[j])%d!=0&&k-j>1&&(p[k]-p[j])/d+1==2&&d*2<=n){
						ans++;
				}else if(w==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
