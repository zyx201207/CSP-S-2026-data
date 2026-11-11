#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				int w=a[j];
				a[j]=a[j+1];
				a[j+1]=w;
			}
		}
	}
	cout<<a[n-m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
