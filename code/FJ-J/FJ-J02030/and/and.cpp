#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxa;
	int a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		maxa=a[0];
		for(int i=1;i<n;i++){
			if(maxa<a[i]){
				maxa=a[i];
			}
			
		}
		cout<<maxa;
	}
	if(m==2){
		maxa=a[0]and a[1];
		for(int i=1;i<n;i++){
			for(int j=2;j<n;j++){
				if(maxa<(a[i]& a[j])){
					maxa=a[i]& a[j];
				}
			}
		}
	}
	return 0;
}
