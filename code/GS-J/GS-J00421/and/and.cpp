#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m]={};
	int b=0;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(a[i]>a[i+1]){
			b=a[i];
		}
	}
	cout<<b;
	return 0;
}