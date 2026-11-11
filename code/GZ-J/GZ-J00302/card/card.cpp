//GZ-J00302 遵义市第四中学 马跃腾 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],bb[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c=i,b[300005];
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
				c++;
			}
			else{
				while(a[c]!=a[j]){
					c--;
				}
			}
		}
		for(int j=i;j<=i+c+1;j++){
			bb[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<bb[i]<<" ";
	}
	return 0;
}
