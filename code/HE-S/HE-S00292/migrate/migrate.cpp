#include <iostream>
using namespace std;
int c,t;
int n,d,a[100005],k;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>d>>k; 
	for(int i=0;i>=1;i--){
		for(int j=0;j<=n;j++){
			if(a[i]<a[j]){
				k=a[i];
				a[i]=a[i-j];
				a[i-j]=k;
			}
		}
	}
	return 0;
} 
