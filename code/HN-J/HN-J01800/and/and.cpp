#include<bits/stdc++.h> 
using namespace std;
bool cmp(int a,int b){
		return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int a[n+40];
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout <<a[1];
		return 0;
	}
	int v[n+5][m+5]={};
	for(int i=1;i<=n;i++){
		v[i][1]=a[i];
	}
	for(int p=1;p<=m;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
					v[i][p]=max(v[i-1][p-1]&a[j],v[i][p]);
			}
		}
	}
	
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout <<v[i][j]<<" ";
		}
		cout <<"\n";
	}*/
	cout <<v[n][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
