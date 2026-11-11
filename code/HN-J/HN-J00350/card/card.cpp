#include<bits/stdc++.h>
using namespace std;
int a[500003];
int b[300002];
int c[300002];
int f[300002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int u=1;u<=n;u++){
		for(int i=1;i<=m;i++){
			b[i]=0;
		}
		for(int i=u;i<=n;i++){
			int r=a[i];
			if(b[r]!=0){
				int zh=0;
				
				for(int j=u;j<=n;j++){
					int yyy=a[j];
					if(b[yyy]>b[r])b[yyy]=0;
					else if(b[yyy]>zh)zh=yyy;
				}
			zh++;
			b[r]=zh;
			}
			else{
				b[a[i]]=b[a[i-1]]+1;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]>0)c[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}  
