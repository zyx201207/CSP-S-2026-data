#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],all;
void cz(int x){
	for(int i=1;i<all;i++)if(c[i]==c[all]){
		for(int j=i+1;j<=all;j++)c[j]=0;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)c[j]=0;
		all=1;
		for(int j=1;j<=n;j++,all++){
			c[j]=a[j+i-1];
			cz(1);
		}
		for(int j=1;j<=all;j++)
			b[c[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

