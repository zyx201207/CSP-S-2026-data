#include <iostream> 
using namespace std;
int main()
{
	
	int n,m,a,c[300000];
	
	cin>>n>>m;
	int b[n][300000],r[300000][300000];
	for (int i=0;i<n;i++){
		cin>>a;
		int j=-1;
		while (a!=0){
			c[j]==a%2;
			j-=1;
			a/=2;
		}
		int k=0,l=0;
		while (1){
			if (c[k]==1){
				while(k<300000){
					b[i][l]=c[k];
					k+=1;
				}
				break;
			}
			k+=1;
		}
	}
	int s=0;

	
	return 0;
}
