#include<bits/stdc++.h>
using namespace std;
long long ji[5000002],cun[5000002],you[5000002];
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	int a;
    	cin>>a;
    	ji[i]=a;
	}
	for(int i=0;i<m;i++){
		for(int j=i;j<n;j++){
			for(int z=1;z<=n;z++){
				if(ji[j]==ji[z]){
					for(int q=j;q<z;q++){
						cun[q]=1;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(cun[j]==0){
				you[j]++;
			}else{
				cun[j]=0;
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		if(you[i]){
			cout<<you[i]<<" ";
		}
		
	}
    return 0;
}
