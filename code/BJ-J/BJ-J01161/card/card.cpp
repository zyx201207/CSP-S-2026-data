#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1][2],b[m+1],c[m+1];
	for(int i=1;i<=n;i++)cin>>a[i][0];
	for(int i=1;i<=m;i++)b[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)c[j]=0;
		for(int j=1;j<=n;j++)a[j][1]=0;
		for(int j=i;j<=n;j++){
			if(c[a[j][0]]!=0&&a[j][1]!=-1){
				for(int z=c[a[j][0]];z<j;z++){
					a[z][1]=-1;
				}
				c[a[j][0]]=0;
			}
			else{
				if(a[j][1]!=-1)c[a[j][0]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(a[j][1]!=-1){
				b[a[j][0]]++;
				
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}