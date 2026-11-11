#include<bits/stdc++.h>
using namespace std;
int n,m,a[500025],z=0,b[500025];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int t=1;t<=n;t++){
		z=0;
		for(int i=t;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i]==a[j]){
					z=max(z,j);
				} 
		z=max(z,t);
		for(int i=z;i<=n;i++)
		b[a[i]]++;	
	}
	for(int i=1;i<=m;i++)
	cout<<b[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

