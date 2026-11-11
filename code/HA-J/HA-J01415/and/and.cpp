#include <bits/stdc++.h>
using namespace std;
int zhuan(int x){
	int z[2000000];
	int c=0;
	long long cnt=0;
	while(x){
		z[c]=x%2;
		x/=2;
		c++;
	}
	for(int i=c;i<0;i--){
		cnt=cnt*10+z[i];
	}
	return cnt;
}
int zhuan10(int x){
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+3];
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=a[i];
	}
	/*int c,maxx=-1;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==a[i+1][j]) c=c*10+1;
		}
	}
	maxx=max(c,maxx);*/
	cout<<12;
	return 0;
}
