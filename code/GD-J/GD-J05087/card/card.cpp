#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[1000000005];
int b[1000000005];
int c[1000000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int y=1;y<n;y++){
		for(int j=1;j<=n;j++)b[j]=a[j];
		for(int i=y;i<n;i++){
			for(int j=i;j<n;j++){
				if(a[i]==a[j+1]){
					for(int x=i;x<j+1;x++) b[x]=0;
					i=j+1;
				}
			}
		}
		for(int j=y;j<=n;j++) {
			if(b[j]!=0){
				for(int x=1;x<=m;x++)if(b[j]==x)c[x]++;
			}
		}
	}
	c[m]+=1;
	for(int y=1;y<=m;y++){
		cout<<c[y]<<' ';
	}
	return 0;
}
