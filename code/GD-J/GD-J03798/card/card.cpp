#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int n,m,a[1005],abcd=0,zhuo[1005]={0},sss[105][1005]={0},aaa[1005]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=i;j<n;j++){
			for(int k=0;k<n;k++){
				if(zhuo[k]==a[j]){
					for(int p=k;p<n;p++){
						zhuo[p]=0;
						k=p;
					}
					zhuo[k]=a[j];
				}
				else{
					zhuo[k]=a[j];
				}
			}
		}
		for(int u=0;u<n;u++){
			sss[abcd][u]=zhuo[u];
		}
		abcd++;
		zhuo[1005]={0};
	}
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			if(sss[x][y]==a[x]){
				aaa[x]++;
			}
		}
	}
	for(int qwert=0;qwert<m;qwert++){
		cout<<aaa[qwert];
		if(qwert<m-1){
			cout<<" ";
		}
	}
	return 0; 
}
