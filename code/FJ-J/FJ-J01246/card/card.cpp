#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int b[N],dis[N];
int n,m;
int a[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int len=0;
			for(int j=i;j<=n;j++){
				if(b[a[j]]==0){
					b[a[j]]=1;
					c[++len]=a[j];
				}else{
					while(c[len]!=a[j]){
						b[c[len]]=0;
						c[len]=0;
						len--;
					}
				}
			}
			for(int j=1;j<=len;j++){
				dis[c[j]]++;
				c[j]=0;
			}
			for(int j=1;j<=m;j++){
				b[j]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<dis[i]<<" ";
			}
	}
	return 0;
} 
