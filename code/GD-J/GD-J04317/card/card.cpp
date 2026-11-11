#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){//判断每个i
	int sum=0;
		for(int j=1;j<=n;j++){//局数 
		int b[n+5]={0};
			for(int k=j;k<=n;k++){
				bool c=1;
				b[k]=a[k];
				for(int l=k-1;l>=j;l--){
					if(b[l]==b[k]){
						c=1;
						break;
					}
				}
				if(c==1){
					for(int l=k-1;l>=j;k--){
						b[l]=-1;
					}
				}
			}
			for(int k=1;k<=n;k++){
				if(b[k]==i)sum++;
			}
		}
		cout<<sum<<" ";
	}
return 0;
} 
