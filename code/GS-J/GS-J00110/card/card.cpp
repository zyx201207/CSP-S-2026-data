#include<bits/stdc++.h>
using namespace std;
int n, m;
int cards[5*10^5+1];
int now[5*10^5+1];
int gui[2], lon[1];
int fuhe[5*10^5+1];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int ii=1;ii<=n;ii++){
		cin>>cards[ii];
	}
		
	for(int nm=1;nm<=n;nm++){
		lon[0]=n-nm+1;
		lon[1]=0;
		for(int i=nm;i<=lon[0];i++){
			gui[0]=0;
			now[i]=cards[i+lon[i]];
			for(int j=i-1;j>=1;j--){
				if(now[i]==now[j]){
					for(int k=j;k<=i;k++){
						now[k]=0;
						lon[1]++;
						if(k==i){
							lon[1]--;
						}
						gui[0]=1;
					}
				}
			}
			if(gui[0]==1){
				i=i-lon[1];
				lon[0]=lon[0]-lon[1];
				now[i]=cards[i];
			}
			
		}
		for(int fu=1;fu<=lon[0];fu++){
			fuhe[now[fu]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<fuhe[i];
	}
	
	
    return 0;
}

