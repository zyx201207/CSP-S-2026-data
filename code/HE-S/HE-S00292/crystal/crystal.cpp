#include <iostream> 
using namespace std;
int n,m,a[100005],sum=0,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
	cin>>a[i];	
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			r=a[i];
			a[i]=a[i+1];
			a[i+1]=r;
		}
	}
	cout <<r;
 	return 0;
}
