#include<bits/stdc++.h> 
using namespace std;
int po,jk;
int a[200002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>po>>jk;
	for(int i=1;i<=po;i++){
		cin>>a[i];
	}
	for(int i=1;i<=po;i++){
		for(int j=1;j<=po;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	cout<<a[jk];return 0;
}
