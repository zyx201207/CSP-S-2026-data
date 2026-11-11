#include <iostream>
using namespace std;
int ma[0][0];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int m;
	int max=0;
	cin >> n >> m;
	int g[100][100];
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(i%4!=0&&j%4!=0){
				cin >> g[i][j];
				max==1;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if((i%4!=0||j%4!=0)&&max==0) {
				cin >> g[i][j];
				max=2;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(max==0) {
				cin >> g[i][j];
			}
		}
	}

	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(g[i][j]>ma[0][0]) {
				max=g[i][j];
			}
		}
	}
	cout << g[i][j];
	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
