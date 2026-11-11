#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(m==2){
			if(a[i]==a[i+1]){
				cout<<a[i];
				break;
			}
		} 
	}
	return 0;
}
