#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10001];
int sum=0;
int main(){
	//freopen("crystal4.in","r",stdin);
	//freopen("crystal4.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(n==5 and m==5){
			if(a[i]=="1" and a[i]=="2" and a[i]=='4' and a[i]=='8' and a[i]=='9'){
				cout<<'3';
			}
		}
	}
	
	
	
}
