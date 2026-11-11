#include<bits/stdc++.h>
using namespace std;
int a[200002];
int a2[200002];
int num;
int find(int m,int n,int y){
	if(m<=1){
		for(int i;i<=n;i++){
			if(a2[i]!=-1){
				num=max(num,a2[i]&y);
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a2[i]!=-1){
				a2[i]=-1;
				find(m-1,n,a2[i]);
				a2[i]=a[i];
			}
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a2[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		a2[i]=-1;
		find(m-1,n,a2[i]);
		a2[i]=a[i];
	}
	cout<<num;
	return 0;
}
