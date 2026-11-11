#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool A=0,B=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			B=0;
		}
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		int s=a[1]&a[2];
		cout<<s;
		return 0;
	}
	if(B==0){
		A=1;
	}
	int ans=0;
	if(A){
		cout<<a[m];
		return 0;
	}
	if(B){
		int k=1,note=0;
		for(int i=1;i<=m;i++){
			note&=a[i];
		}
		cout<<note;
	}
	return 0;
}
