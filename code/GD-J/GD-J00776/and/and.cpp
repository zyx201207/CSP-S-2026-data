#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	if(m==1){
		int max=-1;
		int q;
		for(int i=0;i<n;i++){
			cin>>q;
			if(q>max){
				max=q;
			}
			}
			cout<<max; 
		}
		if(m==2){
			int a[2010];
			int max=-1;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=(n-1);i++){
				for(int j=i+1;j<=n;j++){
					if(a[i]&a[j]>max){
						max=a[i]&a[j];
					}
				}
			}
			cout<<max;
		}
		if(m==n){
			int a=0;
			int z;
			for(int i=1;i<=n;i++){
				cin>>z;
				a=a&z;
			}
			cout<<a;
		}
	return 0;
} 
