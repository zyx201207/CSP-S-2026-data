#include<iostream>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m],c[n];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int s[m+5][m+5];
	int s2[m+5];
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
		s[i][j]=c[j];
		for(int k=1;k<=j;k++){
			if(s[i][k]==c[j])
			for(int y=1;y<=j;y++) s[i][y]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			c[s[i][j]]++;
	}
}
	for(int i=1;i<=n;i++)
	cout<<c[i] ;
	return 0;
}
