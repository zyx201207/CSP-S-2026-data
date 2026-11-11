#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int q=1;q<=n;q++){
			b[q]=a[q];
		}
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(b[k]==b[j]){
					for(int p=k;p<j;p++)b[p]=0;
				}
			}	
		}
		for(int d=i;d<=n;d++)c[b[d]]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
