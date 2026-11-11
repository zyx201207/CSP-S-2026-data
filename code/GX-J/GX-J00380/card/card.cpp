#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,q=0;
	cin>>n>>m;
	int a[n],l[n],s[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int z=0;z<n;z++){
			l[z]=a[i+z];
			for(int j=0;j<z;j++){
				if(l[j]==l[z]){
					q=z;
					
				}
			}	
		}
		for(int f=q;f<=n;f+=1){
			for(int j=0;j<=0;j++){
				if(l[f]==j)s[j]++;
				}
		}
	}
	for(int i=0;i<m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
