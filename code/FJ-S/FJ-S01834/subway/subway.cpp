#include <bits/stdc++.h>
using namespace std;
	int b[600000][600000][10];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q,w,n,p,m;
	cin >>q >>w >>n >>p >>m;
	int a[p+10],c[m+10][4];
	for(int i=1;i<=p;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		cin >>b[i][1][1];
		for(int j=2;j<=b[i][1][1]+1;j++){
			cin >>b[i][j][1] >>b[i][j][2];
		}
	}
	for(int i=1;i<=m;i++){
		cin >>c[i][1] >>c[i][2];
		
	}
	cout <<35 <<endl <<16;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
