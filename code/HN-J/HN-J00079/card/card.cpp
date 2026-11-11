#include<bits/stdc++.h>
using namespace std;
int n,m,x[500001],y[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		x[i]=c;
		y[c]++;
	}
	for(int i=1;i<m;i++){
		y[i]+=(i-2);
	} 
	y[1]+=2;
	y[x[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<y[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
