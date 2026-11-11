#include<bits/stdc++.h>
using namespace std;
int n,m;
int d[200005],f[200005];
int yu(int a[],m,n){
	if(m==2){
		int max2=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n&&j!=i;j++){
				if(max2<a[i]&a[j]){
					max2=a[i]&a[j];
				}
			}
		}
		return max2;
		}
		int max=-1;
		int g[200005]={0};
		for(int i=0;i<n;i++){
			for(int j=0;j<n&&j!=i;j++){
				g[j]=a[i];
			}
			int w=yu(g,m-1,n);
			if(max<&a[i]){
			max=w&a[i];
		}
		}
		return max;
	}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	cout<<yu(d,m,n);
	return 0;
}
