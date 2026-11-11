#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,max=-1,c;
	int a[10005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			c=a[i]&a[j];
			if(a[i]&a[j]>max){
				max=a[i]&a[j];
			}
		}
	}cout<<max;
	return 0;
}
