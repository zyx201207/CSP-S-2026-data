#include<bits/stdc++.h> 
using namespace std;
int n,w; 
bool cmp(int a,int b){
	if(a>b)return true;
	else  return false; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>w;
	long long a[n+10]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	for(int i=0;i<n;i++){
		if(a[0]!=a[i]){
			cout<<a[i];
			break;
		}
	}
	return 0;
}
