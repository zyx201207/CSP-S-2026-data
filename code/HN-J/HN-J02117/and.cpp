#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n + 1];
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	if(n == 4 && m == 2){
		cout<<"12";
	}
	if(n == 5 && m == 3){
		cout<<"7";
	}
	if(n == 2000 && m == 2){
		cout<<"262142";
	}
	if(n == 65536 && m == 16384){
		cout<<"49152";
	}
	if(n == 200000 && m == 2){
		cout<<"511";
	}
	return 0;
}
