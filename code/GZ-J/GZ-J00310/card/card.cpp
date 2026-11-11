//GZ-J00310 遵义市第四中学 张君皓 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100001],e[10001],i;
	cin>>n>>m;
	int b[m+1];
	for(int j=0;j<=m;j++){
		b[j]=0;
	}
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[j]=0;
		}
		for(int j=i;j<=n;j++){
			for(int c=i;c<j;c++){
				if((a[j]==a[c])&&e[c]!=1){
					for(int d=c;d<j;d++){
						e[d]=1;
					}
					break;
				}
			}
		} 
		for(int j=i;j<=n;j++){
			if(e[j]!=1){
				for(int c=1;c<=m;c++){
					if(a[j]==c){
						b[c]++;
					}
				}
			}
		}
			
	}
	for(int j=1;j<=m;j++){
		cout<<b[j]<<" ";
	}
	return 0;
}
