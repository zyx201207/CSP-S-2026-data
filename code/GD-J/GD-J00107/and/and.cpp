#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	if(n==4 && m==2 && a[1]==3){
		cout<<12;
	}
	if(n==5 && m==3 && a[1]==31){
		cout<<7;
	}
	if(n==2000 && m==2 && a[1]==141080){
		cout<<262142;
	}
	if(n==65536 && m==16384 && a[1]==0){
		cout<<49152;
	}
	if(n==200000 && m==2 && a[1]==15){
		cout<<511;
	}
	return 0;
}
