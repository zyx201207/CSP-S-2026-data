#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	if(a>b){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=0;i<m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
