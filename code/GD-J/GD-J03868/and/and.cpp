#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	//freopen("and.in","r",str);
	//freopen("and.out","w",str);
	int n,m;
	int maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>maxx){
				maxx=a[i]&a[j];
			}
		}
	}
	cout<<maxx;
	return 0;
}
