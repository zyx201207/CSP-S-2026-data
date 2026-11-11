#include<iostream>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	int m;
	int a[1000000];
	int v;
	int sum=-1;
	int x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-m+1;i++){
		v=a[i];
		for(int j=i;j<=n;j++){
			v=v%a[j];
			x++;
			if(x==m){
				if(v>sum){
					sum=v;
				}
				v=a[i];
				x=0;
			}
		}
		
	}
	cout<<sum;
	return 0;
}
