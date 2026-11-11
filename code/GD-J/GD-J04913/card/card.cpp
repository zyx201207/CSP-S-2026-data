#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k[n];
	int k2[n];
	int num[m];
	for(int i=0;i<m;i++){
		num[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	for(int i=0;i<n;i++){
		for(int f=0;f<n;f++){
			k2[i]=k[i];
		}
		for(int g=i;g<n;g++){
			for(int h=g-1;h<=i;h--){
				if(k2[g]==k2[h]){
					for(int l=i;l<g;l++){
						k2[l]==0;
					}
				}
			}
		}
		for(int f=1;f<=m;f++){
			for(int g=i;g<n;g++){
				if(k2[g]==f){
					num[f-1]++;
				}
			}
		}
	}
	for(int i=0;i<m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
