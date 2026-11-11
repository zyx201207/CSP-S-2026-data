#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m;
int a[MAXN],ans[MAXN]={0},p[MAXN]={0};
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=m;j<=n;j++){
			if(p[a[j]]==0){
				p[a[j]]==j;
			}
			else{
				
			}
		}
	}
}
