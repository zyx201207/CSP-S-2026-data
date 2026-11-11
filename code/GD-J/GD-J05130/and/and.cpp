#include<iostream>
using namespace std;
int n,m;
int a[100009],ans;
int cpo(int j){
	int po=a[j];
	for(int i=1;i<m;i++){
		 po^=a[j+i];
	}
	return po;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	//for(int i=0;i<m;i++){
		for(int j=0;j<=n-m;j++){
			ans=max(ans,cpo(j));
		}
	//}
	cout<<ans;
	return 0;
}
