#include <iostream> 
using namespace std;
int main()

{
	int m,n,k=0;
	int table[2000000]={},result[20000000]={};
	cin>>n>>m;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int g=0;
	while(g<n){
		for (int i=g;i<n;i++){
			table[i]=a[i];
			for (int j=0;j<i;j++){
				if (table [j]==table[i]){
					for (int t=j;t<i;t++){
						table [t]=0;
					}
					break;
				}	
			}
			for (int j=0;j<=i;j++){
				if (table [j]!=0){
					result [k]++;
				}
			}
			k++;
			
		}
		
		for (int i=g;i<=2000000;i++){
			table[i]=0;
		}
		g++;
	}
	for (int i=0;i<m;i++){
		int p=0;
		for (int j=0;j<20000000;j++){
			if(result[j]==i+1)p++;
		}
		cout<<p<<' ';
	}
	return 0;
}
