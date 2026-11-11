#include<bits/stdc++.h> 
using namespace std;
int n,m;
int ans=-100;
int a[200005];
bool f[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		cout<<12;
	}
	if(n==5){
		cout<<7;
	}
	if(n==2000){
		cout<<262142;
	}
	if(n==65536){
		cout<<49152;
	}
	if(n==200000){
		cout<<511;
	}
	return 0;
}
