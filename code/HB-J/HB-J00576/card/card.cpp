#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		}
		int o=0,p=0;
		for(int i=0;i<n;i++){
			int u=0,y=0;
				for(int j=i;j<=n;j++){
					u+=(s[j]==1);
					y+=(s[j]==2);
					if(s[j]==1){
						y=0;
						}
					}
					if(u)o++;
					
					
					
					if(y)p++;
		}cout<<o<<' '<<p;
	return 0;
}


