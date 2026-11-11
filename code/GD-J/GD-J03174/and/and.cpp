#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r","stdin");
	int n,m,maxx=-1,t=1,a[200010];
	cin>>n>>m;
	;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i]<<" "<<a[j]<<endl;
		}
	}
	cout<<maxx;
	freopen("and.out","w","stdout");
	return 0;
	
} 
