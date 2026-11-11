//GZ-J00303 遵义四中 郑安迪 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={};
	int js[m+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		int b[n+5]={};
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int i=j;i<=n;i++){
			if(b[i]!=0){
				for(int x=i+1;x<=n;x++){
					if(b[i]==b[x]){
						for(int p=i+1;p<=x;p++){
							b[p]=0;
						}
						i=x;
					}
				}
			}
			
			
		}
		for(int i=j;i<=n;i++){
			js[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<js[i]<<" ";
	}
	return 0;
}

