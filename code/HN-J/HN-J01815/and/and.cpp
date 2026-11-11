#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	
	int sum=a[0];
	for(int i=1;i<m;i++){
		sum=(sum&a[i]);
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
