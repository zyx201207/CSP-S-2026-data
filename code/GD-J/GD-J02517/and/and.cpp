#include <bits/stdc++.h>

using namespace std;

int n,m,a[20005],x=-1,i2,j2,ma=127;
	
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int M=1;M<m;M++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>x){
					x=a[i]&a[j];
					i2=i;
					j2=j;
				}
			}
		}
		ma=ma&x;
		x=-1;
		a[j2]=0;
		a[i2]=0;
	}
	cout<<ma;
	return 0;
}
