#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","s",stdout);
	int n,m,maxi=-1;
	cin >>n>>m;
	for(int i=0;i<n;i++){
		cin >>a[i];
	} 
	while(m){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]&a[j]>maxi){
					maxi=a[i]&a[j];
				}
			}
		}
		m-=2;
	}
	cout <<maxi;
	return 0;
}
