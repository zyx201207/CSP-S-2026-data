#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=1;
			for(int k=i;k<=j;k++){
				if(a[k]==a[j])flag=0;
			}
			
		}
	}
	
	
	return 0;
}
