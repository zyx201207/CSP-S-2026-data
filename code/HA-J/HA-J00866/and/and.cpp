#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int two[13]{1,2,4,8,16,32,64,128,256,512,1024,2048};
	int n,m;
	cin>>n>>m;
	int a[100001]={};
	long long a1[100001]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<a[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
