#include<bits/stdc++.h>
using namespace std;
int i,j;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005],z[500005];
	int s[300005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(i<n){
		for(int i=0;i<n;i++){
		int k = 0;
		for(int j=0;j<n;j++){
			if(a[i] == z[j]){
				k=j;
				break;
			}
		}
		if(k!=0){
			for(int g=j;g<n;g++){
				z[g] = 0;
			}
			}
		}
		for(int l=1;l<=m;l++){
			for(int f = 0;f<n;f++){
				if(l == z[f]){
					s[l]++;
					break;
				}
			}
		}	
		i++;
	}
	for(int v=1;v<=m;v++){
		cout<<s[v]<<" ";
	}
	
	
	
	
	return 0;
}
