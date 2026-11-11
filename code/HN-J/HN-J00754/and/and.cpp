#include<bits/stdc++.h>
using namespace std;
int n,m,mx=0,a[200001],b=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<m+i;j++){
			if(i!=j){
				b=a[i]&a[j];
				if(b>mx){
					mx=b;
				}
			}
		}
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
