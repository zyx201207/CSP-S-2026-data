#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=-1;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		if(a[i]>=5&&x==-1){
			x=a[i];
		}
		else if(a[i]>=5&&a[i]<x){
			x=a[i];
		}
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
