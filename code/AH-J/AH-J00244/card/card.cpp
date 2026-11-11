#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[500005],x[500005],z[1000];
int main(){
	//freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++){
			x[j]=t[j];
			for(int k=1;k<=j;k++){
				if(x[k]==x[j]){
					for(int p=k;p<j;p++){
						x[p]=0;
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(x[j]!=0){
				z[i]++;
			}
		}
		for(int j=1;j<=n;j++){
			x[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<" ";
	}
}
