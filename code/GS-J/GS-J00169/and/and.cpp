#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k,w=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-m+1;i++){
		k=2147483647;
		for(int j=0;j<m;j++){
			k&=a[j+i];
			
		}if(k>w) w=k;
	}cout<<w;
}
