#include<bits/stdc++.h>
using namespace std;
int a[100005],m,n,k,b[1005],s[1005],q=1,p=1,j,o;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=1005;i++){
		s[i]=i;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int z=1;z<=n;z++){
		for(j=z;j<=n;j++){
			b[j]=a[z];
		}
				for(int i=2;i<=j;i++){
					for(int v=1;v<=n-1;v++){
						o=v;
						while(o==0){
							if(b[i]==b[i-o]){
							for(int g=i-o;g=i;g++){
								b[g]=0;
							}
						}
						}
					}	
					} 
			} 
		for(int k=1;k>=n;k++){
			for(int i=1;i<=n;i++){
				if(b[i]==s[q]){
					s[q]++;
				}
		}
		q++;
			}
	
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
