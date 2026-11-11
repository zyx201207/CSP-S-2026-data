#include<bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[n],d[m];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) d[i]=0;
	for(int c=1;c<=n;c++){
		for(int i=c;i<=n;i++){
			b[i]=a[i];
		
			for(int j=1;j<=i;j++){
				if(b[i]==b[j]){
					for(int g=j;g<i;g++) b[g]=0;
				}
			}
		
		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++)
			{
				if(b[i]==j) {
					d[j]+=1;
				}
			}
		}
		for(int i=1;i<=n;i++) b[i]=0;
		
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<' ';

	return 0;
}
