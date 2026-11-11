#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m=0,ans=0;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0; i<n; i++){
		if(a[i]==a[i+1]){
		cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


