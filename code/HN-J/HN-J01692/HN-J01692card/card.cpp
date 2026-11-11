#include<iostream>
using namespace std;
int a[134];
int main(){
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		int j=i;
		cout<<j;
		i--;
		j=i+n;
		cout<<j;
		while(j>i+n+m){
			j=j*j;
			n=j/2+3;
			m=n/3+m;
			a[9+i-m]=2;
		}
		i=m;
	}
	return 0;
}
